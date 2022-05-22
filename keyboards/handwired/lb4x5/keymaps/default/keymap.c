#include "lb4x5.h"

#define _0 0
#define _ALT 1
#define _NUM 2
#define _MOD 3
// #define _SYM 4

// custom keycodes
enum Keycodes{
    SHRUG = SAFE_RANGE,
    PWD
};

// Tap Dance declarations
enum {
    ALT_TAB,
    CTL_TAB,
    QUIT,
    STP_RS,
    STT_DBLD,
    ESC_LCK
};

// enum unicode_names {
//     TH_UP   ,//👍
//     TH_DN   ,//👎
//     HAPPY   ,//😁
//     SAD     ,//😢
//     ANGRY   ,//🤬
//     FU      ,//😊
//     LAUGH   ,//😂
//     MUMBLE  ,//🤔
//     GRIN    ,//😬
//     MUSCLE  ,//💪
//     HEART   ,//❤️
//     POPPER  ,//🎉
//     GUN     ,//🔫
//     SUSHI   ,//🍣
//     BEER    ,//🍻
//     SMIRK   ,//😏
// };

// const uint32_t PROGMEM unicode_map[] = {
//     [TH_UP]  = 0x1F4AA, //👍
//     [TH_DN]  = 0x1F44E, //👎
//     [HAPPY]  = 0x1F601, //😁
//     [SAD]    = 0x1F622, //😢
//     [ANGRY]  = 0x1F92C, //🤬
//     [FU]     = 0x1F60A, //😊
//     [LAUGH]  = 0x1F602, //😂
//     [MUMBLE] = 0x1F914, //🤔
//     [GRIN]   = 0x1F62C, //😬
//     [MUSCLE] = 0x1F4AA, //💪
//     [HEART]  = 0x2764,  //❤️
//     [POPPER] = 0x1F389, //🎉
//     [GUN]    = 0x1F52B, //🔫
//     [SUSHI]  = 0x1F363, //🍣
//     [BEER]   = 0x1F37B, //🍻
//     [SMIRK]  = 0x1F60F, //😏
// };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// [_0] = KEYMAP(
//     TD(ESC_LCK), A(KC_GRV),    C(S(KC_ESC)),  HYPR(KC_C),
//     TD(CTL_TAB), TD(STT_DBLD), TD(STP_RS),    TD(QUIT),
//     KC_F9,       KC_F10,       KC_F11,        S(KC_F11),
//     TD(ALT_TAB), G(KC_T),      G(KC_E),       G(KC_F),
//     MO(_ALT),    C(KC_MINS),   C(S(KC_MINS)), KC_LCTL
// ),

[_0] = KEYMAP(
    TD(ESC_LCK), TD(STT_DBLD), TD(STP_RS),    TD(QUIT),
    KC_F9,       KC_F10,       KC_F11,        S(KC_F11),
    A(KC_GRV),   G(KC_T),      G(KC_E),       G(KC_F),
    HYPR(KC_C),  TD(ALT_TAB),  TD(CTL_TAB),   C(S(KC_ESC)),
    MO(_ALT),    C(KC_MINS),   C(S(KC_MINS)), KC_ENT
),

[_ALT] = KEYMAP(
    _______,  _______,  _______, RESET,
    _______,  _______,  _______, _______,
    _______,  _______,  _______, _______,
    _______,  _______,  _______, _______,
    _______,  _______,  _______, _______
)

// [_ALT] = KEYMAP(
//     DF(_NUM), _______,   _______, _______,
//     _______,  _______,   _______, RESET,
//     _______,  _______,   _______, _______,
//     _______,  UC_M_MA,   UC_M_WC, _______,
//     _______,  MO(_SYM), _______, _______
// ),

// #define __ZERO LT(_MOD, KC_P0)
// [_NUM] = KEYMAP(
//     DF(_0), KC_PSLS, KC_PAST, KC_PMNS,
//     KC_P7,  KC_P8,   KC_P9,   KC_PPLS,
//     KC_P4,  KC_P5,   KC_P6,   KC_PPLS,
//     KC_P1,  KC_P2,   KC_P3,   KC_PENT,
//     __ZERO, __ZERO,  KC_PDOT, KC_PENT
// ),

// [_MOD] = KEYMAP(
//     _______,  KC_PERC, KC_AMPR, KC_TILD,
//     _______,  _______, _______, KC_PIPE,
//     _______,  _______, _______, KC_PIPE,
//     _______,  _______, _______, _______,
//     _______,  _______, KC_COMM, _______
// ),

// [_SYM] = KEYMAP(
//     SHRUG,     X(TH_UP), X(TH_DN),  X(HAPPY),
//     X(SAD),    X(ANGRY), X(FU),     X(LAUGH),
//     X(MUMBLE), X(GRIN),  X(MUSCLE), X(HEART),
//     X(POPPER), X(GUN),   X(SUSHI),  X(BEER),
//     X(SMIRK),  _______,  _______,   PWD
// ),

};

void alt_each(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 1)
        register_code(KC_LALT);
    tap_code(KC_TAB);
}

void ctl_each(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 1)
        register_code(KC_LCTL);
    tap_code(KC_TAB);
}

void alt_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_LALT);
}

void ctl_reset(qk_tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_LCTL);
}

void fn_close(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 1)
        tap_code16(C(KC_W));
    else
        tap_code16(A(KC_F4));
}

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // TODO test tapping term time, ==> what happens if the key is held?
    [ALT_TAB] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(alt_each, NULL, alt_reset, 200),
    [CTL_TAB] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(ctl_each, NULL, ctl_reset, 200),
    [QUIT] = ACTION_TAP_DANCE_FN(fn_close),
    [STP_RS] = ACTION_TAP_DANCE_DOUBLE(S(KC_F5), C(S(KC_F5))),
    [STT_DBLD] = ACTION_TAP_DANCE_DOUBLE(KC_F5, C(S(KC_B))),
    [ESC_LCK] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, G(KC_L))
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // TODO HYPR + KC_Fxx layer triggering ahk scripts
    switch(keycode) {
        // case SHRUG:
        //     if (record->event.pressed) {
        //         send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
        //         return false;
        //     }
        // break;
        case PWD:
            if(record->event.pressed) {
                return false;
            }
    default: break;
    }

	return true;
}
