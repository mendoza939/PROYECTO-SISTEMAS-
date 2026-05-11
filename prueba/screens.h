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
    SCREEN_ID_MENU_ALTURA = 8,
    SCREEN_ID_MENU_HUM = 9,
    _SCREEN_ID_LAST = 9
};

typedef struct _objects_t {
    lv_obj_t *logo_ec;
    lv_obj_t *logo_ec_1;
    lv_obj_t *main;
    lv_obj_t *segunda;
    lv_obj_t *frecuencia_card;
    lv_obj_t *temperatu;
    lv_obj_t *presionn;
    lv_obj_t *menu_altura;
    lv_obj_t *menu_hum;
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
    lv_obj_t *bt_naltura;
    lv_obj_t *presion_2;
    lv_obj_t *bt_naltura_1;
    lv_obj_t *presion_3;
    lv_obj_t *op_crono;
    lv_obj_t *bt_ncrono;
    lv_obj_t *tit_crono;
    lv_obj_t *titulo1_4;
    lv_obj_t *titulo1_5;
    lv_obj_t *name;
    lv_obj_t *titulo1_6;
    lv_obj_t *titulo1_7;
    lv_obj_t *titulo1_8;
    lv_obj_t *titulo1_9;
    lv_obj_t *titulo1_11;
    lv_obj_t *airebar;
    lv_obj_t *titulo1_30;
    lv_obj_t *airebar_1;
    lv_obj_t *teclado;
    lv_obj_t *titulo1_2;
    lv_obj_t *btn_2;
    lv_obj_t *saturacion_2;
    lv_obj_t *saturacion;
    lv_obj_t *porc;
    lv_obj_t *alerta;
    lv_obj_t *slider_alarma;
    lv_obj_t *ajuste_alarma;
    lv_obj_t *valor_alarma;
    lv_obj_t *ajuste_alarma_1;
    lv_obj_t *container_dedo_1;
    lv_obj_t *label_dedo_1;
    lv_obj_t *obj0;
    lv_obj_t *frecu;
    lv_obj_t *btn_3;
    lv_obj_t *saturacion_3;
    lv_obj_t *freculabel;
    lv_obj_t *frecumeter;
    lv_obj_t *bp_mlabel;
    lv_obj_t *ledlatido;
    lv_obj_t *roller_frecu;
    lv_obj_t *container_dedo;
    lv_obj_t *label_dedo;
    lv_obj_t *frecu_anteriores;
    lv_obj_t *temperatura;
    lv_obj_t *btn_4;
    lv_obj_t *saturacion_4;
    lv_obj_t *arc_temp;
    lv_obj_t *label_temp;
    lv_obj_t *celsius;
    lv_obj_t *titulo1_18;
    lv_obj_t *titulo1_19;
    lv_obj_t *titulo1_20;
    lv_obj_t *titulo1_21;
    lv_obj_t *titulo1_22;
    lv_obj_t *titulo1_23;
    lv_obj_t *presio;
    lv_obj_t *btn_5;
    lv_obj_t *saturacion_5;
    lv_obj_t *arc_presion;
    lv_obj_t *label_presion;
    lv_obj_t *pascales;
    lv_obj_t *titulo1_12;
    lv_obj_t *titulo1_13;
    lv_obj_t *titulo1_14;
    lv_obj_t *titulo1_15;
    lv_obj_t *titulo1_16;
    lv_obj_t *titulo1_17;
    lv_obj_t *titulo_altura;
    lv_obj_t *btn_8;
    lv_obj_t *saturacion_6;
    lv_obj_t *label_altura;
    lv_obj_t *metros;
    lv_obj_t *arc_altura;
    lv_obj_t *titulo_altura_1;
    lv_obj_t *arc_altura_1;
    lv_obj_t *btn_9;
    lv_obj_t *saturacion_7;
    lv_obj_t *label_altura_1;
    lv_obj_t *porce;
    lv_obj_t *titulo1_24;
    lv_obj_t *titulo1_25;
    lv_obj_t *titulo1_26;
    lv_obj_t *titulo1_27;
    lv_obj_t *titulo1_28;
    lv_obj_t *titulo1_29;
} objects_t;

extern objects_t objects;

typedef struct {
    lv_meter_scale_t *Frecu;
    lv_meter_indicator_t *frecuround;
} screen_frecuencia_card_state_t;

typedef struct {
    lv_meter_scale_t *scale;
    lv_meter_indicator_t *lineAlt;
} screen_menu_altura_state_t;

extern screen_frecuencia_card_state_t screen_frecuencia_card_state;
extern screen_menu_altura_state_t screen_menu_altura_state;

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

void create_screen_menu_altura();
void tick_screen_menu_altura();

void create_screen_menu_hum();
void tick_screen_menu_hum();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/