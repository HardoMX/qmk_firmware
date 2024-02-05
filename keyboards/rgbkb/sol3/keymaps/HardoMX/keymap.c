
/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <https://github.com/Legonut> wrote this file.  As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day, and
 * you think this stuff is worth it, you can buy me a beer in return. David Rauseo
 * ----------------------------------------------------------------------------
 */

#include QMK_KEYBOARD_H

/* Soul
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ GESC │   1  │   2  │   3  │   4  │   5  │  NA  │  │   =  │   6  │   7  │   8  │   9  │   0  │ BkSp │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │   Q  │   W  │   L  │   D  │   P  │  NA  │  │   -  │   K  │   M  │   U  │   Y  │   ;  │   \  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │FNCAPS│   A  │   S  │   R  │   T  │   G  │  NA  │  │   )  │   F  │   N  │   E  │   I  │   O  │   '  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │Shift │   Z  │   X  │   C  │   V  │   J  │  NA  │  │   }  │   B  │   H  │   ,  │   .  │   /  │Enter │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Ctrl │  Win │  Alt │RGBADJ│  NO  │      │  NA  │  │  NA  │      │   [  │   ]  │   {  │   }  │ RCTL │
 * └──────┴──────┴──────┴──────┴──────┤ Space├──────┤  ├──────┤ Space├──────┴──────┴──────┴──────┴──────┘
 *                                    │      │ DEL  │  │ Enter│      │
 *                                    └──────┴──────┘  └──────┴──────┘
 * ┌──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┐
 * │Scr dn│scr up│ Prev │ Play │ Next │                              │Vol Dn│Vol Up│ Prev │ Play │ Next │
 * └──────┴──────┴──────┴──────┴──────┘                              └──────┴──────┴──────┴──────┴──────┘
 */

enum sol_layers {
    _SOUL,
    _QWERTY,
    _FN,
    _ADJUST
};

enum sol_keycodes {
    // Disables touch processing
    TCH_TOG = SAFE_RANGE,
    MENU_BTN,
    MENU_UP,
    MENU_DN,
    RGB_RST
};

#define FN       MO(_FN)
#define ADJUST   MO(_ADJUST)
#define QWERTY   DF(_QWERTY)
#define SOUL     DF(_SOUL)
#define FN_CAPS  LT(_FN, KC_CAPS)
#define MUT_PLY  LT(KC_MPLY, KC_MUTE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_SOUL] = LAYOUT(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_NO,                 KC_EQL,  KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_L,    KC_D,  KC_P,   KC_NO,                 KC_MINS, KC_K,   KC_M,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
        FN_CAPS, KC_A,    KC_S,    KC_R,    KC_T,  KC_G,   KC_NO,                 KC_RPRN, KC_F,   KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_J,   KC_NO,                 KC_RCBR, KC_B,   KC_H,    KC_COMM, KC_DOT,  KC_SLSH, SC_SENT,
        KC_LCTL, KC_LGUI, KC_LALT, ADJUST, KC_NO, KC_SPC, KC_NO, KC_DEL, KC_ENT, KC_NO, KC_SPC, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_RCTL,

        KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MNXT, MUT_PLY, KC_MPRV,                                      KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV
    ),

    [_QWERTY] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,                   _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,                   _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,                   _______, KC_N,    KC_M,    _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_FN] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______,                   _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,
        _______, KC_HOME, KC_UP,   KC_END,  _______, _______, _______,                   _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PSCR,  KC_PGUP,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,                   _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_PGDN,
        _______, AU_TOGG, MU_TOGG, MU_NEXT, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, CK_TOGG,   CK_UP, CK_DOWN, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,

        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______,                   _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, RGB_SAD, RGB_VAI, RGB_SAI, QK_BOOT, _______, _______,                   _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______,
        _______, RGB_HUD, RGB_VAD, RGB_HUI, RGB_RST, _______, DM_REC1,                   _______, _______, KC_P4,   KC_P5,   KC_P6,   _______, _______,
        _______, RGB_SPD, _______, RGB_SPI, _______, _______, DM_RSTP,                   _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, SOUL,
        _______, RGB_RMOD,RGB_TOG, _______, RGB_MOD, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, KC_NUM,  _______, QWERTY,

        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
        case MENU_BTN:
            if (record->event.pressed) {
                rgb_menu_selection();
            }
            return false;
        case MENU_UP:
            if (record->event.pressed) {
                rgb_menu_action(true);
            }
            return false;
        case MENU_DN:
            if (record->event.pressed) {
                rgb_menu_action(false);
            }
            return false;
        case RGB_RST:
            if (record->event.pressed) {
                eeconfig_update_rgb_matrix_default();
            }
            return false;
        case TCH_TOG:
            if (record->event.pressed) {
                touch_encoder_toggle();
            }
            return false;  // Skip all further processing of this key
        default:
            return true;
    }
}

void render_layer_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _SOUL:
            oled_write_ln_P(PSTR("SOUL "), false);
            break;
        case _QWERTY:
            oled_write_ln_P(PSTR("QWRTY"), false);
            break;
        case _FN:
            oled_write_ln_P(PSTR("FN   "), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adjst"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0]       = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
                  ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [1 ... 3] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______),
                  ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) }
};
#endif
