#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// enum declarations

// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_SATURACION = 0,
    FLOW_GLOBAL_VARIABLE_ALARMA = 1,
    FLOW_GLOBAL_VARIABLE_FRECUVALOR = 2,
    FLOW_GLOBAL_VARIABLE_FRECU_LED = 3,
    FLOW_GLOBAL_VARIABLE_HAY_DEDO = 4,
    FLOW_GLOBAL_VARIABLE_UMBRAL_ALARMA = 5,
    FLOW_GLOBAL_VARIABLE_OPCIONES_HISTORIAL = 6,
    FLOW_GLOBAL_VARIABLE_SELECCION_HISTORIAL = 7,
    FLOW_GLOBAL_VARIABLE_PRES_VALOR = 8,
    FLOW_GLOBAL_VARIABLE_TEMP_VALOR = 9,
    FLOW_GLOBAL_VARIABLE_ALT_VALOR = 10
};

// Native global variables

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/