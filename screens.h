#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Screens

enum ScreensEnum {
    _SCREEN_ID_FIRST = 1,
    SCREEN_ID_LOGO_EC = 1,
    SCREEN_ID_LOGO_EC_1 = 2,
    SCREEN_ID_MAIN = 3,
    SCREEN_ID_SEGUNDA = 4,
    SCREEN_ID_FRECUENCIA_CARD = 5,
    SCREEN_ID_TEMPERATU = 6,
    SCREEN_ID_PRESIONN = 7,
    _SCREEN_ID_LAST = 7
};

typedef struct _objects_t {
    lv_obj_t *logo_ec;
    lv_obj_t *logo_ec_1;
    lv_obj_t *main;
    lv_obj_t *segunda;
    lv_obj_t *frecuencia_card;
    lv_obj_t *temperatu;
    lv_obj_t *presionn;
    lv_obj_t *logo1;
    lv_obj_t *btn_6;
    lv_obj_t *voler;
    lv_obj_t *logo_ecc;
    lv_obj_t *logo1_1;
    lv_obj_t *btn_7;
    lv_obj_t *voler_1;
    lv_obj_t *logo_ecc_1;
    lv_obj_t *titulo1_1;
    lv_obj_t *btn_1;
    lv_obj_t *saturacion_1;
    lv_obj_t *frecuencia_car_1;
    lv_obj_t *frecuencia_2;
    lv_obj_t *temperatura_1;
    lv_obj_t *presion_a_1;
    lv_obj_t *presion_1;
    lv_obj_t *titulo1_2;
    lv_obj_t *btn_2;
    lv_obj_t *saturacion_2;
    lv_obj_t *saturacion;
    lv_obj_t *porc;
    lv_obj_t *obj0;
    lv_obj_t *frecu;
    lv_obj_t *btn_3;
    lv_obj_t *saturacion_3;
    lv_obj_t *temperatura;
    lv_obj_t *btn_4;
    lv_obj_t *saturacion_4;
    lv_obj_t *presio;
    lv_obj_t *btn_5;
    lv_obj_t *saturacion_5;
} objects_t;

extern objects_t objects;

void create_screen_logo_ec();
void tick_screen_logo_ec();

void create_screen_logo_ec_1();
void tick_screen_logo_ec_1();

void create_screen_main();
void tick_screen_main();

void create_screen_segunda();
void tick_screen_segunda();

void create_screen_frecuencia_card();
void tick_screen_frecuencia_card();

void create_screen_temperatu();
void tick_screen_temperatu();

void create_screen_presionn();
void tick_screen_presionn();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/