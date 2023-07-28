/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include "keycodes.h"
#include QMK_KEYBOARD_H
#include "features/custom_shift_keys.h"

enum layers {
    _QWERTY = 0,
    _HANDDOWN,
    _MINECRAFT,
    _NAV,
    _NUM,
    _SYM,
    _HANDSYM,
    _HANDSYM2,
    _FUNCTION,
    _LCTRL,
    _LALT,
    _LGUI,
};

#define _ KC_TRNS
#define __ KC_TRNS
#define ___ KC_TRNS
#define ____ KC_TRNS
#define _____ KC_TRNS
#define ______ KC_TRNS
#define _______ KC_TRNS
#define LCS(...) LCTL(LSFT(__VA_ARGS__))
#define LCG(...) LCTL(LGUI(__VA_ARGS__))
#define KC_LCS C_S_T(OSM(MOD_LCTL | MOD_LSFT))
#define KC_LCA LCA(KC_NO)
#define KC_LSA LSA(KC_NO)
#define KC_LSG SGUI(KC_NO)
#define KC_LCG LCG(KC_NO)
#define KC_LAG LAG(KC_NO)
#define KC_LCAG LCAG(KC_NO)
#define KC_MEH MEH(KC_NO) // TODO: Use one shot mod
#define KC_SGUI SGUI(KC_NO)
#define KC_HYPR HYPR(KC_NO)
#define SMO(X) LM(X, MOD_LSFT)

enum custom_keycodes { KC_DUMMY_CUSTOM = SAFE_RANGE, KC_QU, KC_TH, KC_CH, KC_SH, KC_WH, KC_GH, KC_PH, KC_RPRN_MACRO };

// Aliases for readability
#define QWERTY DF(_QWERTY)
#define HANDDOWN DF(_HANDDOWN)
#define MINCRFT TO(_MINECRAFT)

#define SYM MO(_SYM)
#define HSYM MO(_HANDSYM)
#define NUM MO(_NUM)
#define NAV MO(_NAV)
#define FKEYS MO(_FUNCTION)

#define CC_LEFT LCTL(KC_LEFT)
#define CC_DOWN LCTL(KC_DOWN)
#define CC_UP LCTL(KC_UP)
#define CC_RGHT LCTL(KC_RGHT)

#define KC_S_Q LSFT(KC_Q)
#define KC_S_Z LSFT(KC_Z)

#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define CST_ESC MT(MOD_LCTL | MOD_LSFT, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ESC MT(MOD_LALT, KC_ESC)
#define ALT_BSP MT(MOD_LALT, KC_BSPC)
#define SFT_BSP MT(MOD_LSFT, KC_BSPC)
#define SFT_ESC MT(MOD_LSFT, KC_ESC)
#define GUI_ESC MT(MOD_LGUI, KC_ESC)
#define ALT_ENT MT(MOD_LALT, KC_ENT)
#define ALT_TAB MT(MOD_LALT, KC_TAB)
#define GUI_ENT MT(MOD_LGUI, KC_ENT)
#define GUI_TAB MT(MOD_LGUI, KC_TAB)
#define GUI_BSP MT(MOD_LGUI, KC_BSPC)
#define SFT_ENT MT(MOD_LSFT, KC_ENT)
#define SFT_TAB MT(MOD_LSFT, KC_TAB)
#define SFT_SPC MT(MOD_LSFT, KC_SPC)
#define CTL_ENT MT(MOD_LCTL, KC_ENT)
#define CTL_TAB MT(MOD_LCTL, KC_TAB)
#define SYM_ENT LT(_SYM, KC_ENT)
#define SYM_TAB LT(_SYM, KC_TAB)
#define HSY_TAB LT(_HANDSYM, KC_TAB)
#define KR_CSYM LT(_HANDSYM, KC_R)
#define NUM_DEL LT(_NUM, KC_DEL)
#define NUM_ENT LT(_NUM, KC_ENT)
#define NUM_TAB LT(_NUM, KC_TAB)
#define NUM_MIN LT(_NUM, KC_MINS)
#define NAV_ENT LT(_NAV, KC_ENT)
#define NAV_TAB LT(_NAV, KC_TAB)
#define NAV_UND LT(_NAV, KC_UNDS)
#define NAV_BSL LT(_NAV, KC_BSLS)
#define NAV_ESC LT(_NAV, KC_ESC)
#define NAV_DEL LT(_NAV, KC_DEL)
#define NAV_BSP LT(_NAV, KC_BSPC)
#define HSYM_R LT(_HANDSYM, KC_R)

#define KC_COPY LCTL(KC_C)
#define KC_CUT LCTL(KC_X)
#define KC_PSTE LCTL(KC_V)
#define KC_UNDO LCTL(KC_Z)

const custom_shift_key_t custom_shift_keys[] = {
    {KC_DOT, KC_LCBR},  //
    {KC_COMM, KC_LBRC}, //
    {KC_MINS, KC_PPLS}, //
    {KC_HASH, KC_UNDS}, //
    {KC_EQL, KC_ASTR},  //
    {KC_SLSH, KC_QUES}, //
    {KC_LPRN, KC_RPRN}, //
    {KC_LBRC, KC_RBRC}, //
    {KC_LCBR, KC_RCBR}, //
    {KC_UNDS, KC_EXLM}, //
    {KC_DLR, KC_CIRC},  //
    {KC_BSLS, KC_AMPR}, //
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

#define COMBOS_TABLE(X)             \
    X(1, KC_DOT, KC_SLSH, KC_EXLM)  \
    X(2, KC_DOT, KC_EQL, KC_COLN)   \
    X(3, KC_EQL, KC_SLSH, KC_BSLS)  \
    X(4, KC_Q, KC_TILD, LSFT(KC_Q)) \
    X(5, KC_Z, KC_TILD, LSFT(KC_Z)) \
    X(6, KC_J, KC_K, KC_ESC)        \
    X(7, KC_B, KC_P, KC_Z)          \
    X(8, KC_X, KC_W, KC_Q)          \
    X(9, KC_T, KC_N, KC_TH)         \
    X(10, KC_C, KC_T, KC_CH)        \
    X(11, KC_S, KC_N, KC_SH)        \
    X(12, KC_W, KC_M, KC_WH)        \
    X(13, KC_G, KC_M, KC_GH)        \
    X(14, KC_F, KC_D, KC_PH)

#define ADAPTIVE_KEYS_DEF() \
    AK_SND_ONLY_START(KC_Q) \
    R_SND(KC_GRV, KC_U)     \
    AK_SND_ONLY_START(KC_G) \
    R_SND(KC_M, KC_L)       \
    AK_SND_ONLY_START(KC_M) \
    R_FST(KC_G, KC_L)       \
    AK_SND_ONLY_START(KC_U) \
    R_SND(KC_H, KC_A)       \
    AK_SND_ONLY_START(KC_A) \
    R_SND(KC_H, KC_U)       \
    AK_SND_ONLY_START(KC_E) \
    R_SND(KC_H, KC_O)       \
    AK_SND_ONLY_START(KC_O) \
    R_SND(KC_H, KC_E)

#define ADAPTIVE_TERM 100
/* https://github.com/openorclose/qmk_firmware/blob/master/keyboards/crkbd/keymaps/openorclose/features/adaptive_keys.h */
/* https://www.reddit.com/r/KeyboardLayouts/comments/smnv1o/adaptive_keys_qmk_implementation/ */
#include "features/adaptive_keys.h"

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).
// TODO: generate hint strings for the oled automatically
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
     CTL_ESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
     ALT_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_DEL,
     KC_MEH,  KC_LPRN, KC_X,    KC_C,    KC_V,    KC_B,    NUM_MIN, _______, _______, SFT_BSP, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RPRN, KC_QUOT,
                                KC_LGUI, NAV_TAB, KC_LSFT, SYM,     KC_LCTL, ALT_ENT, KC_SPC,  CTL_TAB, NAV_BSL, GUI_ENT
    ),

    [_SYM] = LAYOUT(
     KC_LGUI, KC_TILD, KC_GRV,  KC_EXLM, KC_AT,   KC_RPRN,                                     KC_DQUO, KC_CIRC, KC_QUES, KC_PERC, KC_S_Z,  _______,
     KC_LCTL, KC_LCBR, KC_ASTR, KC_DLR,  KC_PIPE, KC_RCBR,                                     KC_QUOT, KC_UNDS, KC_EQL,  KC_BSLS, KC_COLN, _______,
     KC_LCA,  KC_LBRC, KC_Z,    KC_HASH, KC_AMPR, KC_RBRC, KC_F4,   _______, _______, KC_LSFT, KC_SLSH, KC_MINS, KC_PPLS, KC_LT,   KC_GT,   KC_F6,
                                KC_F1,   KC_F2,   KC_F3,   _______, _______, KC_LALT, _______, KC_LCTL, KC_COMM, KC_DOT
    ),

    [_HANDDOWN] = LAYOUT(
     CTL_ESC, KC_X,    KC_W,    KC_M,    KC_G,    KC_K,                                        KC_LPRN, KC_DOT,  KC_EQL,  KC_SLSH, KC_QUOT, KC_BSPC,
     ALT_ESC, KC_S,    KC_C,    KC_N,    KC_T,    KC_J,                                        KC_COMM, KC_A,    KC_E,    KC_I,    KC_H,    KC_SCLN,
     KC_MEH,  KC_B,    KC_P,    KC_L,    KC_D,    KC_V,    KC_DLR, _______, _______,  KC_UNDS, KC_MINS, KC_U,    KC_O,    KC_Y,    KC_F,    KC_DEL,
                                KC_LGUI, NAV_TAB, KC_LSFT, HSYM_R,  KC_LCTL, ALT_ENT, KC_SPC,  CTL_TAB, NAV_BSL, GUI_ENT
    ),

    [_HANDSYM] = LAYOUT(
     KC_LGUI, KC_GRV,  KC_LT,   KC_AT,   KC_BSLS, _______,                                     _______, KC_1,    KC_2,    KC_3,    _______, _______,
     KC_LCTL, KC_TILD, KC_PIPE, KC_GT,   KC_RBRC, _______,                                     _______, KC_4,    KC_5,    KC_6,    KC_AMPR, _______,
     KC_LCA,  KC_Z,    KC_Q,    KC_HASH, KC_RCBR, _______, KC_CIRC, _______, _______, KC_EXLM, _______, KC_7,    KC_8,    KC_9,    KC_PERC, _______,
                                _______, _______, _______, _______, _______, KC_LALT, _______, KC_0,    _______, _______
    ),

    [_HANDSYM2] = LAYOUT(
     KC_LGUI, KC_GRV,  KC_LT,   KC_AT,   KC_BSLS, KC_PERC,                                     _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
     KC_LCTL, KC_TILD, KC_PIPE, KC_GT,   KC_RBRC, KC_AMPR,                                     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,
     KC_LCA,  KC_Z,    KC_Q,    KC_HASH, KC_RCBR, KC_U,    KC_CIRC, _______, _______, KC_EXLM, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   _______,
                                _______, _______, _______, _______, _______, KC_LALT, _______, KC_LCTL,    _______, _______
    ),

    [_MINECRAFT] = LAYOUT(
     KC_1,    ____,    ____,    KC_UP,   ____,    KC_9,                                        ____,    ____,    ____,    ____,    ____,    _______,
     KC_2,    KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_8,                                        ____,    ____,    ____,    ____,    _______, ______,
     KC_3,    KC_LCTL, KC_4,    KC_5,    KC_6,    KC_7,    ___,     _______, _______, ______,  ____,    ____,    _______, ______,  _______, FKEYS,
                                _______, KC_LCTL, KC_LSFT, KC_SPC,  KC_ESC,  _______, ______,  _______, _______, _______
    ),

    [_NUM] = LAYOUT(
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                       KC_LPRN, KC_1,    KC_2,    KC_3,    KC_CIRC, KC_RPRN,
     KC_HYPR, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_MEH,                                      KC_PAST, KC_4,    KC_5,    KC_6,    KC_PSLS, KC_EQL,
     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, KC_BSPC, KC_PPLS, KC_7,    KC_8,    KC_9,    KC_PMNS, KC_UNDS,
                                _______, _______, _______, FKEYS,   _______, KC_BSPC, _______, KC_0,    KC_COMM, KC_DOT
    ),

    [_NAV] = LAYOUT(
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                       CC_LEFT, CC_DOWN, CC_UP,   CC_RGHT, _______,  _______,
     FKEYS,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_MEH,                                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_INS,  _______,
     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
                                _______, _______, _______, _______, _______, KC_CUT,  KC_COPY, KC_PSTE, KC_UNDO, _______
    ),

    [_FUNCTION] = LAYOUT(
     QK_BOOT, KC_PAUS, KC_MPLY, KC_MNXT, KC_MPRV, MINCRFT,                                     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
     _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, HANDDOWN,                                    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PSCR,
     KC_MEH,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  QWERTY,  RGB_TOG, _______, _______, KC_MUTE, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______,
                                KC_NUM,  KC_CAPS, KC_SCRL, RGB_MOD, KC_HYPR, KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20
    )

//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

#ifndef OLED_ENABLE
#define OLED_ENABLE
#endif
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);

        switch (get_highest_layer(layer_state | default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("ESC\nESC\nCSA         NUM\nGUI NAV SFT SYM CTL"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("ESC\nESC\nCSA         NUM\nGUI NAV SFT SYM CTL"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("ESC\nESC\nCSA         NUM\nGUI NAV SFT SYM CTL"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("ESC\nESC\nCSA         NUM\nGUI NAV SFT SYM CTL"), false);
                break;
            default:
                oled_write_P(PSTR("ESC\nESC\nCSA         NUM\nGUI NAV SFT SYM CTL"), false);
        }
        oled_write_P(PSTR("\n"), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));

        switch (get_highest_layer(layer_state | default_layer_state)) {
            case _QWERTY:
                oled_set_cursor(19, 3);
                oled_write_P(PSTR("BS"), false);
                oled_set_cursor(18, 4);
                oled_write_P(PSTR("DEL"), false);
                oled_set_cursor(19, 5);
                oled_write_P(PSTR("FN"), false);
                oled_set_cursor(12, 5);
                oled_write_P(PSTR("ENT"), false);
                oled_set_cursor(3, 6);
                oled_write_P(PSTR("CTL SPC ALT TAB BS"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("BS\rCR\rFN\n      ENT SPC A C M"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("BS\rCR\rFN\n      ENT SPC A C M"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("BS\rCR\rFN\n      ENT SPC A C M"), false);
                break;
            default:
                oled_write_P(PSTR("BS\rCR\rFN\n      ENT SPC A C M"), false);
        }
    }
    return false;
}
#endif

#ifndef ENCODER_ENABLE
#    define ENCODER_ENABLE
#endif
#ifdef ENCODER_ENABLE
#    define LAYER (biton(layer_state))
#    define ENC_TAP(U, D) \
        if (clockwise) {  \
            tap_code(U);  \
        } else {          \
            tap_code(D);  \
        }
#    define ENC_L (index == 0)
#    define ENC_R (index == 1)
#    define ENCS_TAP(LU, LD, RU, RD) \
        {                            \
            if (ENC_L) {             \
                ENC_TAP(LU, LD)      \
            };                       \
            if (ENC_R) {             \
                ENC_TAP(RU, RD)      \
            };                       \
        }
#    define MOD_CHK(KC) (get_mods() & MOD_BIT(KC))
#    define MOD_CTL MOD_CHK(KC_LCTRL)
#    define MOD_ALT MOD_CHK(KC_LALT)
#    define MOD_SFT MOD_CHK(KC_LSFT)
#    define MOD_GUI MOD_CHK(KC_LGUI)
#    define LYR_CHK(L) (IS_LAYER_ON(L))
#    define LYR_CHK(L) (IS_LAYER_ON(L))
bool encoder_update_user(uint8_t index, bool clockwise) {
    /* // clang-format off */
    switch (LAYER) {
        case _FUNCTION:
            ENCS_TAP(KC_VOLU, KC_VOLD, KC_WH_U, KC_WH_D);
            break;
        case _NAV:
            ENCS_TAP(KC_UP, KC_DOWN, KC_RIGHT, KC_LEFT);
            break;
        case _SYM:
        default:
            if (MOD_GUI) {
                ENCS_TAP(KC_RIGHT, KC_LEFT, KC_UP, KC_DOWN);
            } else {
                ENCS_TAP(KC_WH_R, KC_WH_L, KC_WH_U, KC_WH_D);
            }
    }
    /* // clang-format on */
    return false;
}
#endif

#define X_NAME(N, A, B, C) COMBO_##N##_##A // ##_##B
#define X_ENUM(N, A, B, C) X_NAME(N, A, B, C),
#define X_name(N, A, B, C) combo_##N##_##A // ##_##B
#define X_SEQ(N, A, B, C) const uint16_t PROGMEM X_name(N, A, B, C)[] = {A, B, COMBO_END};
#define X_COMBO(N, A, B, C) [X_NAME(N, A, B, C)] = COMBO(X_name(N, A, B, C), C),

enum combos { COMBOS_TABLE(X_ENUM) };
COMBOS_TABLE(X_SEQ)
combo_t key_combos[COMBO_COUNT] = {COMBOS_TABLE(X_COMBO)};

#define KC_MACRO(KC, STR)            \
    case KC:                         \
        if (record->event.pressed) { \
            SEND_STRING(STR);        \
            return false;            \
        }                            \
        break;
#define KC_MACRO2(COM) KC_MACRO(KC_##COM, #COM)
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    /* Disable combo `SOME_COMBO` on layer `_LAYER_A` */
    switch (combo_index) {
        case X_NAME(6, KC_J, KC_K, KC_ESC):
            if (layer_state_is(_QWERTY)) {
                return false;
            }
            break;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_adaptive_key(keycode, record)) {
        return false;
    }
    if (!process_custom_shift_keys(keycode, record)) {
        return false;
    }
    // Your macros ...
    switch (keycode) {
        KC_MACRO(KC_QU, "qu")
        KC_MACRO(KC_TH, "th")
        KC_MACRO(KC_CH, "ch")
        KC_MACRO(KC_SH, "sh")
        KC_MACRO(KC_WH, "wh")
        KC_MACRO(KC_GH, "gh")
        KC_MACRO(KC_PH, "ph")
        KC_MACRO(KC_RPRN_MACRO, ")")
    }

    return true;
};
