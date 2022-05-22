/* Copyright 2017 Wunder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include QMK_KEYBOARD_H

#define KBD_HALT     false
#define KBD_CONTINUE true

enum layer_names {
    _QW,
    _FN
};

enum tap_dances {
    TD_START,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_START] = ACTION_TAP_DANCE_DOUBLE(KC_F5, KC_F10),
};

//

enum usr_keycodes{
    ENT_SET = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        /* QWERTY
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | CAP LK | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | FN     | RALT   | RGUI   | RCTRL  |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_DEL,  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,         KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_PGUP, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,         KC_BSLS,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_PSCR, KC_PGDN, KC_INS,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,      KC_QUOT,
        KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_HOME, KC_UP,   KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,      KC_RSPC,
        KC_CAPS, KC_LCTL, KC_LALT, KC_LGUI, MO(_FN), KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC,  KC_ENT,  KC_RCTL, KC_APP,  TD(TD_START), MO(_FN)
    ),

    /* FUNCTION
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
        KC_NLCK, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F12,  KC_SLSH, KC_ASTR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS,
        KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, _______, ENT_SET, _______, _______, _______,
        KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______, _______, _______,
        _______, _______, RGB_RMOD,RGB_MOD, MO(_FN), RGB_TOG, KC_P0,   _______, KC_PDOT, KC_PENT, KC_PENT, _______, _______, KC_F10,  MO(_FN)
    )

    // /* QWERTY
    //  * .--------------------------------------------------------------------------------------------------------------------------------------.
    //  * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
    //  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
    //  * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
    //  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
    //  * | CAP LK | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
    //  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
    //  * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
    //  * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
    //  * | LCTRL  | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | FN     | RALT   | RGUI   | RCTRL  |
    //  * '--------------------------------------------------------------------------------------------------------------------------------------'
    //  */
    // [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
    //     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_EQL,  KC_BSPC, KC_DEL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    //     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_RBRC, KC_PGUP, KC_INS,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    //     KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_BSLS, KC_PGDN, KC_PSCR, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    //     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_HOME, KC_UP,   KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    //     KC_CAPS, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, KC_SPC, KC_LEFT, KC_DOWN, KC_RGHT  KC_SPC,  XXXXXXX, KC_ENT,  KC_RCTL, MO(_FN), KC_APP,
    // ),

    // [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
    //     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
    //     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_PGUP, KC_INS,
    //     KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS, KC_PGDN, KC_PSCR,
    //     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_HOME, KC_UP,   KC_END,
    //     KC_CAPS, KC_LCTL, KC_LALT, KC_LGUI, KC_F24,  KC_SPC,  KC_SPC,  XXXXXXX, KC_ENT,  KC_RCTL, MO(_FN), KC_APP,  KC_LEFT, KC_DOWN, KC_RGHT
    // ),
    //
    // /* FUNCTION
    //  * .--------------------------------------------------------------------------------------------------------------------------------------.
    //  * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
    //  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    //  * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
    //  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    //  * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
    //  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    //  * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
    //  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    //  * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
    //  * '--------------------------------------------------------------------------------------------------------------------------------------'
    //  */
    // [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
    //     KC_NLCK, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_SLSH, KC_ASTR,
    //     KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_MINS, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_P7,   KC_P8,   KC_P9,
    //     KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_PLUS, _______, RESET,   _______, _______, _______, KC_P4,   KC_P5,   KC_P6,
    //     KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_PENT, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,
    //     _______, _______, RGB_TOG, _______, RGB_RMOD,RGB_MOD, KC_PENT, KC_PENT, _______, _______, MO(_FN), _______, KC_P0,   _______, KC_PDOT
    // )
};

void matrix_init_user(void) {
    gp103_led_on();
    _delay_ms(100);
    gp103_led_off();
    gp100_led_on();
    _delay_ms(100);
    gp100_led_off();
    capslock_led_on();
    _delay_ms(100);
    capslock_led_off();
}


bool process_record_user_reset(uint16_t keycode, keyrecord_t *record) {
    if (keycode != ENT_SET)
        return KBD_CONTINUE;

    if (record->event.pressed) {
        gp103_led_on();
        register_code(KC_ENT);
        unregister_code(KC_ENT);
        reset_keyboard();
    }

    return KBD_HALT;
}

void led_set_user(uint8_t usb_led) {
    if (IS_LAYER_ON(_FN))
        gp100_led_on();
    else
        gp100_led_off();

    if (usb_led & (1<<USB_LED_CAPS_LOCK))
        capslock_led_on();
    else
        capslock_led_off();
}
