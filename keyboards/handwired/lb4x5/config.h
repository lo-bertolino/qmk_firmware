#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x4080
#define DEVICE_VER      0x0002
#define MANUFACTURER    lo-bertolino
#define PRODUCT         lb4x5
#define DESCRIPTION     4x5 keypad

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 4

/* key matrix pins */
#define MATRIX_ROW_PINS { B7, B3, B2, B1, B0 }
#define MATRIX_COL_PINS { D3, D2, D1, D0 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

#define DEBOUNCING_DELAY 5

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

// #define UNICODE_SELECTED_MODES UC_MAC, UC_WINC
// #define UNICODE_KEY_WINC KC_RALT

#endif
