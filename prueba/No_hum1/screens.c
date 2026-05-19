#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;

static const char *screen_names[] = { "LogoEc", "LogoEc_1", "Main", "Segunda", "FrecuenciaCard", "Temperatu", "Presionn", "MenuAltura", "MenuHum" };
static const char *object_names[] = { "logo_ec", "logo_ec_1", "main", "segunda", "frecuencia_card", "temperatu", "presionn", "menu_altura", "menu_hum", "logo1", "btn_6", "voler", "logo_ecc", "logo1_1", "btn_7", "voler_1", "logo_ecc_1", "titulo1_1", "btn_1", "saturacion_1", "frecuencia_car_1", "frecuencia_2", "temperatura_1", "presion_a_1", "presion_1", "bt_naltura", "presion_2", "bt_naltura_1", "presion_3", "op_crono", "bt_ncrono", "tit_crono", "titulo1_4", "titulo1_5", "name", "titulo1_6", "titulo1_7", "titulo1_8", "titulo1_9", "titulo1_11", "titulo1_30", "airebar_1", "teclado", "titulo1_2", "btn_2", "saturacion_2", "saturacion", "porc", "alerta", "slider_alarma", "ajuste_alarma", "valor_alarma", "ajuste_alarma_1", "container_dedo_1", "label_dedo_1", "obj0", "frecu", "btn_3", "saturacion_3", "freculabel", "frecumeter", "bp_mlabel", "ledlatido", "roller_frecu", "container_dedo", "label_dedo", "frecu_anteriores", "temperatura", "btn_4", "saturacion_4", "arc_temp", "label_temp", "celsius", "titulo1_18", "titulo1_19", "titulo1_20", "titulo1_21", "titulo1_22", "titulo1_23", "presio", "btn_5", "saturacion_5", "arc_presion", "label_presion", "pascales", "titulo1_12", "titulo1_13", "titulo1_14", "titulo1_15", "titulo1_16", "titulo1_17", "titulo_altura", "btn_8", "saturacion_6", "label_altura", "metros", "arc_altura", "titulo_altura_1", "arc_altura_1", "btn_9", "saturacion_7", "label_altura_1", "porce", "titulo1_24", "titulo1_25", "titulo1_26", "titulo1_27", "titulo1_28", "titulo1_29" };

screen_frecuencia_card_state_t screen_frecuencia_card_state;
screen_menu_altura_state_t screen_menu_altura_state;

//
// Event handlers
//

lv_obj_t *tick_value_change_obj;

static void event_handler_cb_logo_ec_btn_6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_logo_ec_1_btn_7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_main_btn_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_main_frecuencia_car_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_main_temperatura_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_main_presion_a_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 8, 0, e);
    }
}

static void event_handler_cb_main_bt_naltura(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_main_bt_naltura_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_main_op_crono(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_dropdown_get_selected(ta);
            assignIntegerProperty(flowState, 14, 3, value, "Failed to assign Selected in Dropdown widget");
        }
    }
}

static void event_handler_cb_main_bt_ncrono(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 15, 0, e);
    }
}

static void event_handler_cb_main_name(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 19, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 19, 0, e);
    }
}

static void event_handler_cb_main_teclado(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_READY) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 27, 0, e);
    }
}

static void event_handler_cb_segunda_btn_2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_segunda_saturacion(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_arc_get_value(ta);
            assignIntegerProperty(flowState, 4, 3, value, "Failed to assign Value in Arc widget");
        }
    }
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_segunda_slider_alarma(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_slider_get_value(ta);
            assignIntegerProperty(flowState, 8, 3, value, "Failed to assign Value in Slider widget");
        }
    }
}

static void event_handler_cb_frecuencia_card_btn_3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_frecuencia_card_roller_frecu(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_roller_get_selected(ta);
            assignIntegerProperty(flowState, 8, 4, value, "Failed to assign Selected in Roller widget");
        }
    }
}

static void event_handler_cb_temperatu_btn_4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_temperatu_arc_temp(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_arc_get_value(ta);
            assignIntegerProperty(flowState, 4, 3, value, "Failed to assign Value in Arc widget");
        }
    }
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_presionn_btn_5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_presionn_arc_presion(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_arc_get_value(ta);
            assignIntegerProperty(flowState, 4, 3, value, "Failed to assign Value in Arc widget");
        }
    }
}

static void event_handler_cb_menu_altura_btn_8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_menu_hum_arc_altura_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_arc_get_value(ta);
            assignIntegerProperty(flowState, 2, 3, value, "Failed to assign Value in Arc widget");
        }
    }
}

static void event_handler_cb_menu_hum_btn_9(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

//
// Screens
//

void create_screen_logo_ec() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.logo_ec = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xda76f2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xf6f1f1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Logo1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.logo1 = obj;
            lv_obj_set_pos(obj, 128, 342);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Universidad ECCI");
        }
        {
            // BTN_6
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_6 = obj;
            lv_obj_set_pos(obj, 166, 409);
            lv_obj_set_size(obj, 149, 49);
            lv_obj_add_event_cb(obj, event_handler_cb_logo_ec_btn_6, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x9b25c5), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // voler
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.voler = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Siguiente");
                }
            }
        }
        {
            // LogoEcc
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.logo_ecc = obj;
            lv_obj_set_pos(obj, 86, -24);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_logo_ecc);
            lv_img_set_zoom(obj, 180);
        }
    }
    
    tick_screen_logo_ec();
}

void tick_screen_logo_ec() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
}

void create_screen_logo_ec_1() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.logo_ec_1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xda76f2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xf6f1f1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Logo1_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.logo1_1 = obj;
            lv_obj_set_pos(obj, 128, 342);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Universidad ECCI");
        }
        {
            // BTN_7
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_7 = obj;
            lv_obj_set_pos(obj, 166, 409);
            lv_obj_set_size(obj, 149, 49);
            lv_obj_add_event_cb(obj, event_handler_cb_logo_ec_1_btn_7, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x9b25c5), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // voler_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.voler_1 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Menu");
                }
            }
        }
        {
            // LogoEcc_1
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.logo_ecc_1 = obj;
            lv_obj_set_pos(obj, 86, -24);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ibio);
            lv_img_set_zoom(obj, 180);
        }
    }
    
    tick_screen_logo_ec_1();
}

void tick_screen_logo_ec_1() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
}

void create_screen_main() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xda76f2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xf6f1f1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Titulo1_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_1 = obj;
            lv_obj_set_pos(obj, 41, 23);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Menu Principal");
        }
        {
            // BTN_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_1 = obj;
            lv_obj_set_pos(obj, 301, 23);
            lv_obj_set_size(obj, 154, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_main_btn_1, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x9b25c5), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Saturacion_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.saturacion_1 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Saturacion de \nOxigeno");
                }
            }
        }
        {
            // FrecuenciaCar_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.frecuencia_car_1 = obj;
            lv_obj_set_pos(obj, 301, 102);
            lv_obj_set_size(obj, 155, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_main_frecuencia_car_1, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x9b25c5), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Frecuencia_2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.frecuencia_2 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Frecuencia Cardiaca");
                }
            }
        }
        {
            // Temperatura_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.temperatura_1 = obj;
            lv_obj_set_pos(obj, 301, 178);
            lv_obj_set_size(obj, 154, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_main_temperatura_1, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x9b25c5), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Temperatura \nAmbiental");
                }
            }
        }
        {
            // PresionA_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.presion_a_1 = obj;
            lv_obj_set_pos(obj, 301, 255);
            lv_obj_set_size(obj, 154, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_main_presion_a_1, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x9b25c5), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Presion_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.presion_1 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Presion");
                }
            }
        }
        {
            // BTNaltura
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.bt_naltura = obj;
            lv_obj_set_pos(obj, 305, 329);
            lv_obj_set_size(obj, 151, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_main_bt_naltura, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x9b25c5), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Presion_2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.presion_2 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Altura");
                }
            }
        }
        {
            // BTNaltura_1
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.bt_naltura_1 = obj;
            lv_obj_set_pos(obj, 305, 406);
            lv_obj_set_size(obj, 152, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_main_bt_naltura_1, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x9b25c5), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Presion_3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.presion_3 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Humedad");
                }
            }
        }
        {
            // OpCrono
            lv_obj_t *obj = lv_dropdown_create(parent_obj);
            objects.op_crono = obj;
            lv_obj_set_pos(obj, 16, 147);
            lv_obj_set_size(obj, 140, LV_SIZE_CONTENT);
            lv_dropdown_set_options_static(obj, "10 minutos\n20 minutos\n30 minutos\n40 minutos\n50 minutos\n60 minutos");
            lv_dropdown_set_dir(obj, LV_DIR_RIGHT);
            lv_dropdown_set_symbol(obj, LV_SYMBOL_RIGHT);
            lv_obj_add_event_cb(obj, event_handler_cb_main_op_crono, LV_EVENT_ALL, flowState);
        }
        {
            // BTNcrono
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.bt_ncrono = obj;
            lv_obj_set_pos(obj, 20, 232);
            lv_obj_set_size(obj, 94, 40);
            lv_obj_add_event_cb(obj, event_handler_cb_main_bt_ncrono, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // TitCrono
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.tit_crono = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Iniciar ");
                }
            }
        }
        {
            // Titulo1_4
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_4 = obj;
            lv_obj_set_pos(obj, 20, 203);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Tiempo restante:");
        }
        {
            // Titulo1_5
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_5 = obj;
            lv_obj_set_pos(obj, 151, 203);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // Name
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.name = obj;
            lv_obj_set_pos(obj, 151, 56);
            lv_obj_set_size(obj, 90, 60);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_placeholder_text(obj, "Ingrese nombre...");
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_main_name, LV_EVENT_ALL, flowState);
        }
        {
            // Titulo1_6
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_6 = obj;
            lv_obj_set_pos(obj, 17, 64);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Usuario:");
        }
        {
            // Titulo1_7
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_7 = obj;
            lv_obj_set_pos(obj, 18, 86);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // Titulo1_8
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_8 = obj;
            lv_obj_set_pos(obj, 17, 297);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x104e7f), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_label_set_text_static(obj, "Densidad del aire actual:");
        }
        {
            // Titulo1_9
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_9 = obj;
            lv_obj_set_pos(obj, 64, 330);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_label_set_text(obj, "");
        }
        {
            // Titulo1_11
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_11 = obj;
            lv_obj_set_pos(obj, 16, 371);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x750e0e), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_label_set_text_static(obj, "Indice de confort termico");
        }
        {
            // Titulo1_30
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_30 = obj;
            lv_obj_set_pos(obj, 86, 398);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_label_set_text(obj, "");
        }
        {
            // Airebar_1
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.airebar_1 = obj;
            lv_obj_set_pos(obj, 29, 434);
            lv_obj_set_size(obj, 150, 10);
            lv_bar_set_range(obj, 0, 50);
        }
        {
            // teclado
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.teclado = obj;
            lv_obj_set_pos(obj, 0, 300);
            lv_obj_set_size(obj, 480, 180);
            lv_obj_add_event_cb(obj, event_handler_cb_main_teclado, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    lv_keyboard_set_textarea(objects.teclado, objects.name);
    
    tick_screen_main();
}

void tick_screen_main() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
    {
        if (!(lv_obj_get_state(objects.op_crono) & LV_STATE_EDITED)) {
            int32_t new_val = evalIntegerProperty(flowState, 14, 3, "Failed to evaluate Selected in Dropdown widget");
            int32_t cur_val = lv_dropdown_get_selected(objects.op_crono);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.op_crono;
                lv_dropdown_set_selected(objects.op_crono, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 17, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.titulo1_4, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.titulo1_4;
            if (new_val) {
                lv_obj_add_flag(objects.titulo1_4, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_clear_flag(objects.titulo1_4, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 18, 4, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.titulo1_5);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.titulo1_5;
            lv_label_set_text(objects.titulo1_5, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 18, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.titulo1_5, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.titulo1_5;
            if (new_val) {
                lv_obj_add_flag(objects.titulo1_5, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_clear_flag(objects.titulo1_5, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 19, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.name);
        uint32_t max_length = lv_textarea_get_max_length(objects.name);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.name;
            lv_textarea_set_text(objects.name, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 21, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.titulo1_7);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.titulo1_7;
            lv_label_set_text(objects.titulo1_7, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 23, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.titulo1_9);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.titulo1_9;
            lv_label_set_text(objects.titulo1_9, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 25, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.titulo1_30);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.titulo1_30;
            lv_label_set_text(objects.titulo1_30, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 26, 3, "Failed to evaluate Value in Bar widget");
        int32_t cur_val = lv_bar_get_value(objects.airebar_1);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.airebar_1;
            lv_bar_set_value(objects.airebar_1, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_segunda() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.segunda = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xda76f2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xf6f1f1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Titulo1_2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_2 = obj;
            lv_obj_set_pos(obj, 105, 29);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Monitor de Saturacion");
        }
        {
            // BTN_2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_2 = obj;
            lv_obj_set_pos(obj, 166, 409);
            lv_obj_set_size(obj, 149, 49);
            lv_obj_add_event_cb(obj, event_handler_cb_segunda_btn_2, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x9b25c5), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Saturacion_2
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.saturacion_2 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Volver");
                }
            }
        }
        {
            // Saturacion
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.saturacion = obj;
            lv_obj_set_pos(obj, 36, 180);
            lv_obj_set_size(obj, 182, 193);
            lv_obj_add_event_cb(obj, event_handler_cb_segunda_saturacion, LV_EVENT_ALL, flowState);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 315, 200);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // porc
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.porc = obj;
            lv_obj_set_pos(obj, 380, 200);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "%");
        }
        {
            // Alerta
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.alerta = obj;
            lv_obj_set_pos(obj, 280, 277);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Alerta!!");
        }
        {
            // SliderAlarma
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.slider_alarma = obj;
            lv_obj_set_pos(obj, 174, 131);
            lv_obj_set_size(obj, 133, 16);
            lv_slider_set_range(obj, 80, 100);
            lv_obj_add_event_cb(obj, event_handler_cb_segunda_slider_alarma, LV_EVENT_ALL, flowState);
        }
        {
            // AjusteAlarma
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.ajuste_alarma = obj;
            lv_obj_set_pos(obj, 174, 98);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Alarma:");
        }
        {
            // ValorAlarma
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.valor_alarma = obj;
            lv_obj_set_pos(obj, 240, 98);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // AjusteAlarma_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.ajuste_alarma_1 = obj;
            lv_obj_set_pos(obj, 268, 98);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "%");
        }
        {
            // ContainerDedo_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.container_dedo_1 = obj;
            lv_obj_set_pos(obj, 25, 162);
            lv_obj_set_size(obj, 430, 230);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x0f0e0e), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // LabelDedo_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_dedo_1 = obj;
            lv_obj_set_pos(obj, 45, 255);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 500, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Por favor, coloque su \ndedo en el sensor");
        }
    }
    
    tick_screen_segunda();
}

void tick_screen_segunda() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
    {
        int32_t new_val = evalIntegerProperty(flowState, 4, 3, "Failed to evaluate Value in Arc widget");
        int32_t cur_val = lv_arc_get_value(objects.saturacion);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.saturacion;
            lv_arc_set_value(objects.saturacion, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 5, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj0);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj0;
            lv_label_set_text(objects.obj0, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 7, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.alerta, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.alerta;
            if (new_val) {
                lv_obj_add_flag(objects.alerta, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_clear_flag(objects.alerta, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 8, 3, "Failed to evaluate Value in Slider widget");
        int32_t cur_val = lv_slider_get_value(objects.slider_alarma);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.slider_alarma;
            lv_slider_set_value(objects.slider_alarma, new_val, LV_ANIM_OFF);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 10, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.valor_alarma);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.valor_alarma;
            lv_label_set_text(objects.valor_alarma, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 12, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.container_dedo_1, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.container_dedo_1;
            if (new_val) {
                lv_obj_add_flag(objects.container_dedo_1, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_clear_flag(objects.container_dedo_1, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 13, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.label_dedo_1, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.label_dedo_1;
            if (new_val) {
                lv_obj_add_flag(objects.label_dedo_1, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_clear_flag(objects.label_dedo_1, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_frecuencia_card() {
    screen_frecuencia_card_state_t *state = &screen_frecuencia_card_state;
    (void)state;
    void *flowState = getFlowState(0, 4);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.frecuencia_card = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xda76f2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xf6f1f1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Frecu
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.frecu = obj;
            lv_obj_set_pos(obj, 78, 35);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Menu Frecuencia Cardiaca");
        }
        {
            // BTN_3
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_3 = obj;
            lv_obj_set_pos(obj, 166, 409);
            lv_obj_set_size(obj, 149, 49);
            lv_obj_add_event_cb(obj, event_handler_cb_frecuencia_card_btn_3, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x9b25c5), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Saturacion_3
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.saturacion_3 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Volver");
                }
            }
        }
        {
            // Freculabel
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.freculabel = obj;
            lv_obj_set_pos(obj, 172, 343);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // Frecumeter
            lv_obj_t *obj = lv_meter_create(parent_obj);
            objects.frecumeter = obj;
            lv_obj_set_pos(obj, 121, 78);
            lv_obj_set_size(obj, 239, 240);
            {
                lv_meter_scale_t *scale = lv_meter_add_scale(obj);
                state->Frecu = scale;
                lv_meter_set_scale_ticks(obj, scale, 41, 1, 5, lv_color_hex(0xa0a0a0));
                lv_meter_set_scale_major_ticks(obj, scale, 8, 3, 10, lv_color_hex(0x000000), 10);
                lv_meter_set_scale_range(obj, scale, 0, 200, 300, 120);
                {
                    lv_meter_indicator_t *indicator = lv_meter_add_needle_line(obj, scale, 3, lv_color_hex(0x0000ff), -28);
                    state->frecuround = indicator;
                }
            }
        }
        {
            // BPMlabel
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.bp_mlabel = obj;
            lv_obj_set_pos(obj, 241, 343);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "BPM");
        }
        {
            // ledlatido
            lv_obj_t *obj = lv_led_create(parent_obj);
            objects.ledlatido = obj;
            lv_obj_set_pos(obj, 386, 103);
            lv_obj_set_size(obj, 32, 32);
            lv_led_set_color(obj, lv_color_hex(0xff0000));
        }
        {
            // Roller_Frecu
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.roller_frecu = obj;
            lv_obj_set_pos(obj, 13, 135);
            lv_obj_set_size(obj, 86, 183);
            lv_roller_set_options(obj, "", LV_ROLLER_MODE_INFINITE);
            lv_obj_add_event_cb(obj, event_handler_cb_frecuencia_card_roller_frecu, LV_EVENT_ALL, flowState);
        }
        {
            // ContainerDedo
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.container_dedo = obj;
            lv_obj_set_pos(obj, 111, 78);
            lv_obj_set_size(obj, 337, 317);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x0f0e0e), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // LabelDedo
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_dedo = obj;
            lv_obj_set_pos(obj, 195, 157);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 500, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Por favor,\ncoloque su \ndedo en\n el sensor");
        }
        {
            // Frecu_anteriores
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.frecu_anteriores = obj;
            lv_obj_set_pos(obj, 13, 87);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Lecturas\nanteriores:");
        }
    }
    
    tick_screen_frecuencia_card();
}

void tick_screen_frecuencia_card() {
    screen_frecuencia_card_state_t *state = &screen_frecuencia_card_state;
    (void)state;
    void *flowState = getFlowState(0, 4);
    (void)flowState;
    {
        const char *new_val = evalTextProperty(flowState, 4, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.freculabel);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.freculabel;
            lv_label_set_text(objects.freculabel, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        if (state->frecuround) {
            int32_t new_val = evalIntegerProperty(flowState, 5, 3, "Failed to evaluate Value in Meter widget");
            int32_t cur_val = state->frecuround->start_value;
            if (new_val != cur_val) {
                tick_value_change_obj = objects.frecumeter;
                lv_meter_set_indicator_value(objects.frecumeter, state->frecuround, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
    {
        int32_t new_val = evalIntegerProperty(flowState, 7, 3, "Failed to evaluate Brightness in Led widget");
        if (new_val < 0) new_val = 0;
        else if (new_val > 255) new_val = 255;
        int32_t cur_val = lv_led_get_brightness(objects.ledlatido);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.ledlatido;
            lv_led_set_brightness(objects.ledlatido, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalStringArrayPropertyAndJoin(flowState, 8, 3, "Failed to evaluate Options in Roller widget", "\n");
        const char *cur_val = lv_roller_get_options(objects.roller_frecu);
        if (compareRollerOptions((lv_roller_t *)objects.roller_frecu, new_val, cur_val, LV_ROLLER_MODE_INFINITE) != 0) {
            tick_value_change_obj = objects.roller_frecu;
            lv_roller_set_options(objects.roller_frecu, new_val, LV_ROLLER_MODE_INFINITE);
            tick_value_change_obj = NULL;
        }
    }
    {
        if (!(lv_obj_get_state(objects.roller_frecu) & LV_STATE_EDITED)) {
            int32_t new_val = evalIntegerProperty(flowState, 8, 4, "Failed to evaluate Selected in Roller widget");
            int32_t cur_val = lv_roller_get_selected(objects.roller_frecu);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.roller_frecu;
                lv_roller_set_selected(objects.roller_frecu, new_val, LV_ANIM_OFF);
                tick_value_change_obj = NULL;
            }
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 9, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.container_dedo, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.container_dedo;
            if (new_val) {
                lv_obj_add_flag(objects.container_dedo, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_clear_flag(objects.container_dedo, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 10, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.label_dedo, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.label_dedo;
            if (new_val) {
                lv_obj_add_flag(objects.label_dedo, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_clear_flag(objects.label_dedo, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_temperatu() {
    void *flowState = getFlowState(0, 5);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.temperatu = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xda76f2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xf6f1f1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Temperatura
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.temperatura = obj;
            lv_obj_set_pos(obj, 60, 31);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Menu Temperatura Ambiente");
        }
        {
            // BTN_4
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_4 = obj;
            lv_obj_set_pos(obj, 306, 413);
            lv_obj_set_size(obj, 149, 49);
            lv_obj_add_event_cb(obj, event_handler_cb_temperatu_btn_4, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x9b25c5), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Saturacion_4
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.saturacion_4 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Volver");
                }
            }
        }
        {
            // ArcTemp
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.arc_temp = obj;
            lv_obj_set_pos(obj, 32, 119);
            lv_obj_set_size(obj, 223, 243);
            lv_obj_add_event_cb(obj, event_handler_cb_temperatu_arc_temp, LV_EVENT_ALL, flowState);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0x8e65a9), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xec5eb2), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xbc119b), LV_PART_KNOB | LV_STATE_DEFAULT);
        }
        {
            // LabelTemp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_temp = obj;
            lv_obj_set_pos(obj, 65, 206);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_44, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // Celsius
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.celsius = obj;
            lv_obj_set_pos(obj, 166, 206);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_44, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "°C");
        }
        {
            // Titulo1_18
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_18 = obj;
            lv_obj_set_pos(obj, 271, 134);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Valor inicial: ");
        }
        {
            // Titulo1_19
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_19 = obj;
            lv_obj_set_pos(obj, 271, 227);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Valor final:");
        }
        {
            // Titulo1_20
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_20 = obj;
            lv_obj_set_pos(obj, 272, 179);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // Titulo1_21
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_21 = obj;
            lv_obj_set_pos(obj, 272, 273);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // Titulo1_22
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_22 = obj;
            lv_obj_set_pos(obj, 32, 355);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Diferencia en el intervalo: ");
        }
        {
            // Titulo1_23
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_23 = obj;
            lv_obj_set_pos(obj, 355, 355);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
    }
    
    tick_screen_temperatu();
}

void tick_screen_temperatu() {
    void *flowState = getFlowState(0, 5);
    (void)flowState;
    {
        int32_t new_val = evalIntegerProperty(flowState, 4, 3, "Failed to evaluate Value in Arc widget");
        int32_t cur_val = lv_arc_get_value(objects.arc_temp);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.arc_temp;
            lv_arc_set_value(objects.arc_temp, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 5, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_temp);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_temp;
            lv_label_set_text(objects.label_temp, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 9, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.titulo1_20);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.titulo1_20;
            lv_label_set_text(objects.titulo1_20, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 10, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.titulo1_21);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.titulo1_21;
            lv_label_set_text(objects.titulo1_21, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 12, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.titulo1_23);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.titulo1_23;
            lv_label_set_text(objects.titulo1_23, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_presionn() {
    void *flowState = getFlowState(0, 6);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.presionn = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xda76f2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xf6f1f1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Presio
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.presio = obj;
            lv_obj_set_pos(obj, 147, 22);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Menu Presion");
        }
        {
            // BTN_5
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_5 = obj;
            lv_obj_set_pos(obj, 315, 405);
            lv_obj_set_size(obj, 149, 49);
            lv_obj_add_event_cb(obj, event_handler_cb_presionn_btn_5, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x9b25c5), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Saturacion_5
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.saturacion_5 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Volver");
                }
            }
        }
        {
            // ArcPresion
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.arc_presion = obj;
            lv_obj_set_pos(obj, 34, 64);
            lv_obj_set_size(obj, 265, 254);
            lv_arc_set_range(obj, 0, 1000);
            lv_obj_add_event_cb(obj, event_handler_cb_presionn_arc_presion, LV_EVENT_ALL, flowState);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0x8e65a9), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xec5e72), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xf3213f), LV_PART_KNOB | LV_STATE_DEFAULT);
        }
        {
            // LabelPresion
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_presion = obj;
            lv_obj_set_pos(obj, 68, 166);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_44, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // Pascales
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.pascales = obj;
            lv_obj_set_pos(obj, 172, 166);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_44, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "hPa");
        }
        {
            // Titulo1_12
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_12 = obj;
            lv_obj_set_pos(obj, 15, 335);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Diferencia en el intervalo: ");
        }
        {
            // Titulo1_13
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_13 = obj;
            lv_obj_set_pos(obj, 311, 77);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Valor inicial: ");
        }
        {
            // Titulo1_14
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_14 = obj;
            lv_obj_set_pos(obj, 311, 116);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // Titulo1_15
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_15 = obj;
            lv_obj_set_pos(obj, 311, 178);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Valor final:");
        }
        {
            // Titulo1_16
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_16 = obj;
            lv_obj_set_pos(obj, 311, 216);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // Titulo1_17
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_17 = obj;
            lv_obj_set_pos(obj, 337, 335);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
    }
    
    tick_screen_presionn();
}

void tick_screen_presionn() {
    void *flowState = getFlowState(0, 6);
    (void)flowState;
    {
        int32_t new_val = evalIntegerProperty(flowState, 4, 3, "Failed to evaluate Value in Arc widget");
        int32_t cur_val = lv_arc_get_value(objects.arc_presion);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.arc_presion;
            lv_arc_set_value(objects.arc_presion, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 5, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_presion);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_presion;
            lv_label_set_text(objects.label_presion, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 9, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.titulo1_14);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.titulo1_14;
            lv_label_set_text(objects.titulo1_14, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 11, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.titulo1_16);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.titulo1_16;
            lv_label_set_text(objects.titulo1_16, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 12, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.titulo1_17);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.titulo1_17;
            lv_label_set_text(objects.titulo1_17, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_menu_altura() {
    screen_menu_altura_state_t *state = &screen_menu_altura_state;
    (void)state;
    void *flowState = getFlowState(0, 7);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.menu_altura = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xda76f2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xf6f1f1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // TituloAltura
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo_altura = obj;
            lv_obj_set_pos(obj, 165, 23);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Menu Altura");
        }
        {
            // BTN_8
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_8 = obj;
            lv_obj_set_pos(obj, 166, 409);
            lv_obj_set_size(obj, 149, 49);
            lv_obj_add_event_cb(obj, event_handler_cb_menu_altura_btn_8, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x9b25c5), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Saturacion_6
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.saturacion_6 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Volver");
                }
            }
        }
        {
            // LabelAltura
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_altura = obj;
            lv_obj_set_pos(obj, 126, 330);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_44, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // metros
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.metros = obj;
            lv_obj_set_pos(obj, 306, 330);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_44, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "m");
        }
        {
            // ArcAltura
            lv_obj_t *obj = lv_meter_create(parent_obj);
            objects.arc_altura = obj;
            lv_obj_set_pos(obj, 125, 78);
            lv_obj_set_size(obj, 230, 230);
            {
                lv_meter_scale_t *scale = lv_meter_add_scale(obj);
                state->scale = scale;
                lv_meter_set_scale_ticks(obj, scale, 41, 1, 5, lv_color_hex(0xa0a0a0));
                lv_meter_set_scale_major_ticks(obj, scale, 5, 2, 10, lv_color_hex(0x000000), 10);
                lv_meter_set_scale_range(obj, scale, 0, 5000, 300, 100);
                {
                    lv_meter_indicator_t *indicator = lv_meter_add_needle_line(obj, scale, 3, lv_color_hex(0x0000ff), -28);
                    state->lineAlt = indicator;
                }
            }
        }
    }
    
    tick_screen_menu_altura();
}

void tick_screen_menu_altura() {
    screen_menu_altura_state_t *state = &screen_menu_altura_state;
    (void)state;
    void *flowState = getFlowState(0, 7);
    (void)flowState;
    {
        const char *new_val = evalTextProperty(flowState, 4, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_altura);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_altura;
            lv_label_set_text(objects.label_altura, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        if (state->lineAlt) {
            int32_t new_val = evalIntegerProperty(flowState, 6, 3, "Failed to evaluate Value in Meter widget");
            int32_t cur_val = state->lineAlt->start_value;
            if (new_val != cur_val) {
                tick_value_change_obj = objects.arc_altura;
                lv_meter_set_indicator_value(objects.arc_altura, state->lineAlt, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
}

void create_screen_menu_hum() {
    void *flowState = getFlowState(0, 8);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.menu_hum = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xda76f2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xf6f1f1), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // TituloAltura_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo_altura_1 = obj;
            lv_obj_set_pos(obj, 143, 23);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Menu Humedad");
        }
        {
            // ArcAltura_1
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.arc_altura_1 = obj;
            lv_obj_set_pos(obj, 33, 108);
            lv_obj_set_size(obj, 266, 233);
            lv_obj_add_event_cb(obj, event_handler_cb_menu_hum_arc_altura_1, LV_EVENT_ALL, flowState);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0x8e65a9), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xec5e72), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xf3213f), LV_PART_KNOB | LV_STATE_DEFAULT);
        }
        {
            // BTN_9
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_9 = obj;
            lv_obj_set_pos(obj, 315, 409);
            lv_obj_set_size(obj, 149, 49);
            lv_obj_add_event_cb(obj, event_handler_cb_menu_hum_btn_9, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x9b25c5), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Saturacion_7
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.saturacion_7 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Volver");
                }
            }
        }
        {
            // LabelAltura_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_altura_1 = obj;
            lv_obj_set_pos(obj, 76, 199);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_44, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // porce
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.porce = obj;
            lv_obj_set_pos(obj, 179, 199);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_44, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "%");
        }
        {
            // Titulo1_24
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_24 = obj;
            lv_obj_set_pos(obj, 299, 108);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Valor inicial: ");
        }
        {
            // Titulo1_25
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_25 = obj;
            lv_obj_set_pos(obj, 299, 213);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Valor final:");
        }
        {
            // Titulo1_26
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_26 = obj;
            lv_obj_set_pos(obj, 299, 158);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // Titulo1_27
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_27 = obj;
            lv_obj_set_pos(obj, 299, 266);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // Titulo1_28
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_28 = obj;
            lv_obj_set_pos(obj, 23, 341);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "Diferencia en el intervalo: ");
        }
        {
            // Titulo1_29
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.titulo1_29 = obj;
            lv_obj_set_pos(obj, 347, 341);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_width(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_height(obj, 10193, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x060606), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
    }
    
    tick_screen_menu_hum();
}

void tick_screen_menu_hum() {
    void *flowState = getFlowState(0, 8);
    (void)flowState;
    {
        int32_t new_val = evalIntegerProperty(flowState, 2, 3, "Failed to evaluate Value in Arc widget");
        int32_t cur_val = lv_arc_get_value(objects.arc_altura_1);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.arc_altura_1;
            lv_arc_set_value(objects.arc_altura_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 5, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_altura_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_altura_1;
            lv_label_set_text(objects.label_altura_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 9, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.titulo1_26);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.titulo1_26;
            lv_label_set_text(objects.titulo1_26, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 10, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.titulo1_27);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.titulo1_27;
            lv_label_set_text(objects.titulo1_27, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 12, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.titulo1_29);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.titulo1_29;
            lv_label_set_text(objects.titulo1_29, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_logo_ec,
    tick_screen_logo_ec_1,
    tick_screen_main,
    tick_screen_segunda,
    tick_screen_frecuencia_card,
    tick_screen_temperatu,
    tick_screen_presionn,
    tick_screen_menu_altura,
    tick_screen_menu_hum,
};
void tick_screen(int screen_index) {
    if (screen_index >= 0 && screen_index < 9) {
        tick_screen_funcs[screen_index]();
    }
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen(screenId - 1);
}

//
// Fonts
//

ext_font_desc_t fonts[] = {
#if LV_FONT_MONTSERRAT_8
    { "MONTSERRAT_8", &lv_font_montserrat_8 },
#endif
#if LV_FONT_MONTSERRAT_10
    { "MONTSERRAT_10", &lv_font_montserrat_10 },
#endif
#if LV_FONT_MONTSERRAT_12
    { "MONTSERRAT_12", &lv_font_montserrat_12 },
#endif
#if LV_FONT_MONTSERRAT_14
    { "MONTSERRAT_14", &lv_font_montserrat_14 },
#endif
#if LV_FONT_MONTSERRAT_16
    { "MONTSERRAT_16", &lv_font_montserrat_16 },
#endif
#if LV_FONT_MONTSERRAT_18
    { "MONTSERRAT_18", &lv_font_montserrat_18 },
#endif
#if LV_FONT_MONTSERRAT_20
    { "MONTSERRAT_20", &lv_font_montserrat_20 },
#endif
#if LV_FONT_MONTSERRAT_22
    { "MONTSERRAT_22", &lv_font_montserrat_22 },
#endif
#if LV_FONT_MONTSERRAT_24
    { "MONTSERRAT_24", &lv_font_montserrat_24 },
#endif
#if LV_FONT_MONTSERRAT_26
    { "MONTSERRAT_26", &lv_font_montserrat_26 },
#endif
#if LV_FONT_MONTSERRAT_28
    { "MONTSERRAT_28", &lv_font_montserrat_28 },
#endif
#if LV_FONT_MONTSERRAT_30
    { "MONTSERRAT_30", &lv_font_montserrat_30 },
#endif
#if LV_FONT_MONTSERRAT_32
    { "MONTSERRAT_32", &lv_font_montserrat_32 },
#endif
#if LV_FONT_MONTSERRAT_34
    { "MONTSERRAT_34", &lv_font_montserrat_34 },
#endif
#if LV_FONT_MONTSERRAT_36
    { "MONTSERRAT_36", &lv_font_montserrat_36 },
#endif
#if LV_FONT_MONTSERRAT_38
    { "MONTSERRAT_38", &lv_font_montserrat_38 },
#endif
#if LV_FONT_MONTSERRAT_40
    { "MONTSERRAT_40", &lv_font_montserrat_40 },
#endif
#if LV_FONT_MONTSERRAT_42
    { "MONTSERRAT_42", &lv_font_montserrat_42 },
#endif
#if LV_FONT_MONTSERRAT_44
    { "MONTSERRAT_44", &lv_font_montserrat_44 },
#endif
#if LV_FONT_MONTSERRAT_46
    { "MONTSERRAT_46", &lv_font_montserrat_46 },
#endif
#if LV_FONT_MONTSERRAT_48
    { "MONTSERRAT_48", &lv_font_montserrat_48 },
#endif
};

//
//
//

void create_screens() {
    
    eez_flow_init_fonts(fonts, sizeof(fonts) / sizeof(ext_font_desc_t));

// Set default LVGL theme
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    // Initialize screens
    eez_flow_init_screen_names(screen_names, sizeof(screen_names) / sizeof(const char *));
    eez_flow_init_object_names(object_names, sizeof(object_names) / sizeof(const char *));
    
    // Create screens
    create_screen_logo_ec();
    create_screen_logo_ec_1();
    create_screen_main();
    create_screen_segunda();
    create_screen_frecuencia_card();
    create_screen_temperatu();
    create_screen_presionn();
    create_screen_menu_altura();
    create_screen_menu_hum();
}