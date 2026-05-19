#include <Arduino.h>
#include <Wire.h>
#include <Arduino_GFX_Library.h>
#include <lvgl.h>
#include <Adafruit_BMP085.h> 
#include "Adafruit_SHT31.h" // 1. Librería del sensor de humedad
#include "TouchDrvGT911.hpp"
#include "MAX30105.h"
#include "heartRate.h" 
#include "ui.h"        
#include "images.h"
#include "screens.h"
#include "eez-flow.h"
#include "vars.h"

// --- CONSTANTES ---
#define SEA_LEVEL_PRESSURE_HPA 101325
#define EXPANDER_ADDR 0x24 
const int LED_DURATION = 150; 
const long UMBRAL_PRESENCIA = 50000;
const int TAMANO_HISTORIAL = 10;

// --- OBJETOS ---
MAX30105 particleSensor;
Adafruit_BMP085 bmp;
Adafruit_SHT31 sht31 = Adafruit_SHT31(); // 2. Objeto del sensor de humedad
TouchDrvGT911 touch;

// --- PANTALLA ---
Arduino_DataBus *bus = new Arduino_SWSPI(GFX_NOT_DEFINED, 42, 2, 1, GFX_NOT_DEFINED);
Arduino_ESP32RGBPanel *rgbpanel = new Arduino_ESP32RGBPanel(40, 39, 38, 41, 46, 3, 8, 18, 17, 14, 13, 12, 11, 10, 9, 5, 45, 48, 47, 21, 1, 10, 8, 50, 1, 10, 8, 20, 1, 12000000);
Arduino_RGB_Display *gfx = new Arduino_RGB_Display(480, 480, rgbpanel, 2, true, bus, GFX_NOT_DEFINED, st7701_type1_init_operations, sizeof(st7701_type1_init_operations));

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[480 * 40]; 
static lv_disp_drv_t disp_drv;
static lv_indev_drv_t indev_drv;

// --- BIOMETRÍA ---
const byte RATE_SIZE = 2; 
byte rates[RATE_SIZE]; 
byte rateSpot = 0;
long lastBeat = 0; 
int beatAvg;
unsigned long ledTurnOffTime = 0;
unsigned long tiempoBuzzer = 0;
bool estadoBuzzer = false;

int historialFrecu[TAMANO_HISTORIAL];
int indiceHistorial = 0;
char bufferRoller[120];

// --- FUNCIONES ---

void controlarBuzzer(bool activo) {
    Wire.beginTransmission(EXPANDER_ADDR);
    Wire.write(0x02); 
    Wire.write(activo ? 0xFF : 0x00); 
    Wire.endTransmission();
}

void actualizarVisualizacionHistorial() {
    bufferRoller[0] = '\0'; 
    char temp[15];
    for (int i = 0; i < TAMANO_HISTORIAL; i++) {
        int pos = (indiceHistorial - 1 - i + TAMANO_HISTORIAL) % TAMANO_HISTORIAL;
        if (historialFrecu[pos] > 0) {
            sprintf(temp, "%d BPM\n", historialFrecu[pos]);
            strcat(bufferRoller, temp);
        }
    }
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
        data->point.x = 480 - tx[0]; 
        data->point.y = 480 - ty[0];
    } else {
        data->state = LV_INDEV_STATE_REL;
    }
}

void setup() {
    Serial.begin(115200);
    Wire.begin(15, 7);

    Wire.beginTransmission(EXPANDER_ADDR);
    Wire.write(0x03); Wire.write(0x00); 
    Wire.endTransmission();
    controlarBuzzer(false);

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
    bmp.begin();
    
    // 3. Inicializar sensor de humedad (dirección 0x44 por defecto)
    if (!sht31.begin(0x44)) {
        Serial.println("No se encuentra el sensor SHT30");
    }

    for(int i=0; i<TAMANO_HISTORIAL; i++) historialFrecu[i] = 0;
}

void loop() {
    // 1. UI
    static uint32_t last_tick = 0;
    if (millis() - last_tick > 5) {
        lv_tick_inc(millis() - last_tick);
        last_tick = millis();
    }
    lv_timer_handler(); 
    ui_tick();

    // 2. Sensores Ambientales (BMP + SHT30)
    static unsigned long lastAmbient = 0;
    if (millis() - lastAmbient > 2000) {
        // BMP085
        eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_TEMP_VALOR, eez::Value(bmp.readTemperature()));
        eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_PRES_VALOR, eez::Value((int)(bmp.readPressure()/100.0)));
        eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_ALT_VALOR, eez::Value((int)bmp.readAltitude(SEA_LEVEL_PRESSURE_HPA)));
        
        // 4. Lectura de Humedad (SHT30)
        float h = sht31.readHumidity();
        if (!isnan(h)) {
            eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_HUM_VALOR, eez::Value(h));
        }
        
        lastAmbient = millis();
    }

    // 3. Lógica Biométrica
    long irValue = particleSensor.getIR();
    bool estaPresente = (irValue > UMBRAL_PRESENCIA);
    eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_HAY_DEDO, eez::Value(estaPresente));

    bool alarmaCronoActiva = eez::flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_ALARM_CRONO).toBool();
    int umbralSaturacion = eez::flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_UMBRAL_ALARMA).toInt32();

    if (estaPresente) {
        int spo2 = map(irValue, 80000, 160000, 95, 99);
        if (spo2 > 100) spo2 = 100;
        eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_SATURACION, eez::Value(spo2));

        bool peligroSaturacion = (spo2 < umbralSaturacion);
        eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_ALARMA, eez::Value(!peligroSaturacion));

        if (peligroSaturacion || alarmaCronoActiva) {
            if (millis() - tiempoBuzzer > 500) {
                estadoBuzzer = !estadoBuzzer;
                controlarBuzzer(estadoBuzzer);
                tiempoBuzzer = millis();
            }
        } else {
            controlarBuzzer(false);
            estadoBuzzer = false;
        }

        if (checkForBeat(irValue)) {
            long delta = millis() - lastBeat;
            lastBeat = millis();
            float bpmInstant = 60 / (delta / 1000.0);

            if (bpmInstant < 220 && bpmInstant > 40) {
                rates[rateSpot++] = (byte)bpmInstant;
                rateSpot %= RATE_SIZE;
                beatAvg = 0;
                for (byte x = 0; x < RATE_SIZE; x++) beatAvg += rates[x];
                beatAvg /= RATE_SIZE;

                historialFrecu[indiceHistorial] = beatAvg;
                indiceHistorial = (indiceHistorial + 1) % TAMANO_HISTORIAL;
                actualizarVisualizacionHistorial();

                eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_FRECUVALOR, eez::Value(beatAvg));
                eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_FRECU_LED, eez::Value(255));
                ledTurnOffTime = millis() + LED_DURATION;
            }
        }
    } else {
        if (alarmaCronoActiva) {
            if (millis() - tiempoBuzzer > 500) {
                estadoBuzzer = !estadoBuzzer;
                controlarBuzzer(estadoBuzzer);
                tiempoBuzzer = millis();
            }
        } else {
            controlarBuzzer(false);
            estadoBuzzer = false;
        }

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