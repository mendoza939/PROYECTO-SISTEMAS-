#include <Arduino.h>
#include <Wire.h>
#include <Arduino_GFX_Library.h>
#include <lvgl.h>
#include "TouchDrvGT911.hpp"
#include "MAX30105.h"
#include "heartRate.h" 
#include "ui.h"        
#include "images.h"
#include "screens.h"
#include "eez-flow.h"
#include "vars.h"

// --- CONFIGURACIÓN DE PANTALLA ---
Arduino_DataBus *bus = new Arduino_SWSPI(GFX_NOT_DEFINED, 42, 2, 1, GFX_NOT_DEFINED);
Arduino_ESP32RGBPanel *rgbpanel = new Arduino_ESP32RGBPanel(40, 39, 38, 41, 46, 3, 8, 18, 17, 14, 13, 12, 11, 10, 9, 5, 45, 48, 47, 21, 1, 10, 8, 50, 1, 10, 8, 20, 1, 12000000);
Arduino_RGB_Display *gfx = new Arduino_RGB_Display(480, 480, rgbpanel, 1, true, bus, GFX_NOT_DEFINED, st7701_type1_init_operations, sizeof(st7701_type1_init_operations));

TouchDrvGT911 touch;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[480 * 40]; 
static lv_disp_drv_t disp_drv;
static lv_indev_drv_t indev_drv;

// --- SENSOR Y BIOMETRÍA ---
MAX30105 particleSensor;
const byte RATE_SIZE = 2; 
byte rates[RATE_SIZE]; 
byte rateSpot = 0;
long lastBeat = 0; 
int beatAvg;

// --- HISTORIAL ---
const int TAMANO_HISTORIAL = 10;
int historialFrecu[TAMANO_HISTORIAL];
int indiceHistorial = 0;
char bufferRoller[120]; // Buffer para la cadena de texto del Roller

// --- VARIABLES DE CONTROL ---
unsigned long ledTurnOffTime = 0;
const int LED_DURATION = 150; 
const long UMBRAL_PRESENCIA = 50000; 

// --- FUNCIONES DE SOPORTE ---
void actualizarVisualizacionHistorial() {
    bufferRoller[0] = '\0'; 
    char temp[15];
    
    // Construimos la lista: los más recientes primero
    for (int i = 0; i < TAMANO_HISTORIAL; i++) {
        // Lógica circular para mostrar del más nuevo al más viejo
        int pos = (indiceHistorial - 1 - i + TAMANO_HISTORIAL) % TAMANO_HISTORIAL;
        int valor = historialFrecu[pos];
        
        if (valor > 0) {
            sprintf(temp, "%d BPM\n", valor);
            strcat(bufferRoller, temp);
        }
    }
    // Actualizamos el Roller en EEZ
    eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_OPCIONES_HISTORIAL, eez::Value(bufferRoller));
}

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);
    gfx->draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)color_p, w, h);
    lv_disp_flush_ready(disp);
}

void my_touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data) {
    int16_t tx[5], ty[5];
    uint8_t touched = touch.getPoint(tx, ty, 1);
    if (touched > 0) {
        data->state = LV_INDEV_STATE_PR;
        data->point.x = 480 - ty[0]; // Mantengo tu configuración invertida actual
        data->point.y = 480 - tx[0];
    } else {
        data->state = LV_INDEV_STATE_REL;
    }
}

void setup() {
    Serial.begin(115200);
    Wire.begin(15, 7);

    // Encendido del panel
    Wire.beginTransmission(0x24); Wire.write(0x02); Wire.write(0xFF); Wire.endTransmission();
    Wire.beginTransmission(0x24); Wire.write(0x03); Wire.write(0x3A); Wire.endTransmission();
    delay(200);

    gfx->begin();
    gfx->fillScreen(RGB565_BLACK);

    lv_init();
    lv_disp_draw_buf_init(&draw_buf, buf, NULL, 480 * 40);
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = 480;
    disp_drv.ver_res = 480;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    touch.begin(Wire, 0x5D, 15, 7);
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read; 
    lv_indev_drv_register(&indev_drv);

    ui_init(); 

    if (particleSensor.begin(Wire, I2C_SPEED_FAST)) {
        particleSensor.setup(0x1F, 4, 2, 400, 411, 4096);
    }

    // Inicializar historial en 0
    for(int i=0; i<TAMANO_HISTORIAL; i++) historialFrecu[i] = 0;
}

void loop() {
    static uint32_t last_tick = 0;
    if (millis() - last_tick > 5) {
        lv_tick_inc(millis() - last_tick);
        last_tick = millis();
    }
    lv_timer_handler(); 
    ui_tick();

    long irValue = particleSensor.getIR();

    // --- GESTIÓN DEL CONTENEDOR (HAYDEDO) ---
    bool estaPresente = (irValue > UMBRAL_PRESENCIA);
    eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_HAY_DEDO, eez::Value(estaPresente));

    if (estaPresente) {
        if (checkForBeat(irValue) == true) {
            long delta = millis() - lastBeat;
            lastBeat = millis();
            float bpmInstant = 60 / (delta / 1000.0);

            if (bpmInstant < 220 && bpmInstant > 40) {
                rates[rateSpot++] = (byte)bpmInstant;
                rateSpot %= RATE_SIZE;
                beatAvg = 0;
                for (byte x = 0; x < RATE_SIZE; x++) beatAvg += rates[x];
                beatAvg /= RATE_SIZE;

                // --- GUARDAR EN HISTORIAL POR CADA PULSO ESTABLE ---
                historialFrecu[indiceHistorial] = beatAvg;
                indiceHistorial = (indiceHistorial + 1) % TAMANO_HISTORIAL;
                actualizarVisualizacionHistorial();

                // Enviar datos a UI
                eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_FRECUVALOR, eez::Value(beatAvg));
                
                int spo2 = map(irValue, 80000, 160000, 95, 99);
                if (spo2 > 100) spo2 = 100;
                eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_SATURACION, eez::Value(spo2));

                // Alarma (Invertida para Hidden)
                int umbralSlider = eez::flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_UMBRAL_ALARMA).toInt32();
                bool hayPeligro = (spo2 < umbralSlider);
                eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_ALARMA, eez::Value(!hayPeligro));

                // LED
                eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_FRECU_LED, eez::Value(255));
                ledTurnOffTime = millis() + LED_DURATION;
            }
        }
    } else {
        // Reset (Enviamos TRUE a Alarma para OCULTARLA)
        static unsigned long lastReset = 0;
        if (millis() - lastReset > 400) {
            eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_FRECUVALOR, eez::Value(0));
            eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_SATURACION, eez::Value(0));
            eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_ALARMA, eez::Value(true));
            eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_FRECU_LED, eez::Value(0));
            lastReset = millis();
        }
    }

    if (millis() > ledTurnOffTime) {
        eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_FRECU_LED, eez::Value(0));
    }
}