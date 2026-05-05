#include <Arduino.h>
#include <Wire.h>
#include <Arduino_GFX_Library.h>
#include <lvgl.h>
#include "TouchDrvGT911.hpp"
#include "MAX30105.h"
#include "ui.h"       // Interfaz exportada desde EEZ Studio
#include "images.h"   // Archivo generado por EEZ con tus imágenes
#include "screens.h"
#include "eez-flow.h"
#include "vars.h"

// --- CONFIGURACIÓN DE PANTALLA (Waveshare ESP32-S3) ---
Arduino_DataBus *bus = new Arduino_SWSPI(
    GFX_NOT_DEFINED /* DC */, 42 /* CS */,
    2 /* SCK */, 1 /* MOSI */, GFX_NOT_DEFINED /* MISO */);

Arduino_ESP32RGBPanel *rgbpanel = new Arduino_ESP32RGBPanel(
    40 /* DE */, 39 /* VSYNC */, 38 /* HSYNC */, 41 /* PCLK */,
    46 /* R0 */, 3 /* R1 */, 8 /* R2 */, 18 /* R3 */, 17 /* R4 */,
    14 /* G0 */, 13 /* G1 */, 12 /* G2 */, 11 /* G3 */, 10 /* G4 */, 9 /* G5 */,
    5 /* B0 */, 45 /* B1 */, 48 /* B2 */, 47 /* B3 */, 21 /* B4 */,
    1 /* hsync_polarity */, 10 /* hsync_front_porch */, 8 /* hsync_pulse_width */, 50 /* hsync_back_porch */,
    1 /* vsync_polarity */, 10 /* vsync_front_porch */, 8 /* vsync_pulse_width */, 20 /* vsync_back_porch */,
    1 /* pclk_active_neg */, 12000000 /* 12MHz */);

Arduino_RGB_Display *gfx = new Arduino_RGB_Display(
    480, 480, rgbpanel, 1 /* rotation */, true /* auto_flush */,
    bus, GFX_NOT_DEFINED /* RST */,
    st7701_type1_init_operations, sizeof(st7701_type1_init_operations));

// --- TOUCH GT911 ---
TouchDrvGT911 touch;
uint8_t gt911_addr = 0;

// --- LVGL VARIABLES ---
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[480 * 40]; 
static lv_disp_drv_t disp_drv;
static lv_indev_drv_t indev_drv;

// --- SENSOR MAX30105 ---
MAX30105 particleSensor;

// Función para que LVGL dibuje en el hardware
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);
    gfx->draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)color_p, w, h);
    lv_disp_flush_ready(disp);
}

// FUNCIÓN DE LECTURA TOUCH (igual que tu inicial)
void my_touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data) {
    int16_t tx[5], ty[5];
    uint8_t touched = touch.getPoint(tx, ty, 1);

    if (touched > 0) {
        data->state = LV_INDEV_STATE_PR;
        data->point.x = 480 - ty[0]; 
        data->point.y = 480 - tx[0];
        Serial.printf("Touch -> X:%d, Y:%d\n", data->point.x, data->point.y);
    } else {
        data->state = LV_INDEV_STATE_REL;
    }
}

void setup() {
    Serial.begin(115200);
    
    // Iniciar I2C (SDA=15, SCL=7)
    Wire.begin(15, 7);

    // Encendido del panel Waveshare
    Wire.beginTransmission(0x24);
    Wire.write(0x02); Wire.write(0xFF);
    Wire.endTransmission();
    Wire.beginTransmission(0x24);
    Wire.write(0x03); Wire.write(0x3A);
    Wire.endTransmission();
    delay(500);

    // Iniciar Pantalla
    if (!gfx->begin()) {
        Serial.println("Error iniciando pantalla");
        while (1);
    }
    gfx->fillScreen(RGB565_BLACK);

    // Iniciar LVGL
    lv_init();
    lv_disp_draw_buf_init(&draw_buf, buf, NULL, 480 * 40);
    
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = 480;
    disp_drv.ver_res = 480;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    // Iniciar Sensor Touch GT911
    Wire.beginTransmission(0x5D); 
    if (Wire.endTransmission() == 0) {
        gt911_addr = 0x5D;
        if (touch.begin(Wire, gt911_addr, 15, 7)) {
            Serial.println("GT911 inicializado.");
        }
    } else {
        Serial.println("No se encontró GT911.");
    }

    // REGISTRAR DISPOSITIVO DE ENTRADA (Touch)
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read; 
    lv_indev_drv_register(&indev_drv);

    // Inicializar Interfaz de EEZ Studio
    ui_init();

    // Inicializar MAX30105
    if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) {
        Serial.println("Sensor MAX30105 no detectado");
    } else {
        particleSensor.setup(255, 1, 2, 400, 411, 16384);
        Serial.println("MAX30105 inicializado.");
    }
}

void loop() {
    static uint32_t last_tick = 0;
    if (millis() - last_tick > 5) {
        lv_tick_inc(millis() - last_tick);
        last_tick = millis();
    }

    lv_timer_handler(); 
    ui_tick();          

    // --- Lectura del sensor y envío a EEZ Studio ---
    long irValue = particleSensor.getIR();

    static unsigned long lastUpdate = 0;
    if (millis() - lastUpdate > 250) {
        if (irValue < 50000) {
            eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_SATURACION, eez::Value(0));
        } else {
            int spo2 = map(irValue, 80000, 160000, 95, 99);
            if (spo2 > 100) spo2 = 100;
            if (spo2 < 0) spo2 = 0;

            eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_SATURACION, eez::Value(spo2));
            Serial.printf("SpO2: %d %%\n", spo2);
        }
        lastUpdate = millis();
    }

    delay(5);
}
