#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

#include "../../../../indianboy42/keymap_common.h"

#define NULL_LAYER LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL, KC_BSPC, LT(3,KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, LT(2,KC_ENT), KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, MO(15), KC_LCTL, KC_LGUI, KC_LALT, MO(1), KC_SPC, LM(1,MOD_LSFT), KC_LEFT, KC_DOWN, KC_RGHT),
	[1] = LAYOUT(KC_GRV, LCA(KC_Q), LCA(KC_W), LCA(KC_E), LCA(KC_R), LCA(KC_T), LCA(KC_Y), LCA(KC_U), LCA(KC_I), LCA(KC_O), KC_INS, KC_TRNS, KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_TRNS, LCA(KC_Z), LCA(KC_X), MEH(KC_C), MEH(KC_V), KC_QUOT, KC_SLSH, KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP, LCTL(LSFT(KC_P)), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, KC_TRNS, KC_HOME, KC_PGDN, KC_END),
	[2] = LAYOUT( KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCA(KC_NO), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SLSH, TG(15), HYPR(KC_NO), SGUI(KC_NO), MEH(KC_NO), KC_LCTL, C_S_T(OSM(MOD_LCTL|MOD_LSFT)), LCAG(KC_NO), MEH(KC_NO), SGUI(KC_NO), HYPR(KC_NO)),
	[3] = LAYOUT(LCTL(LSFT(KC_ESC)), KC_F13, KC_F14, KC_F15, KC_F16, KC_WH_U, RALT(KC_J), RALT(KC_K), LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), KC_PSCR, LSFT(LALT(KC_F)), KC_BSPC, KC_TRNS, KC_F17, KC_F18, KC_F19, KC_F20, KC_WH_D, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, LCTL(LSFT(KC_P)), KC_NO, KC_F21, KC_F22, KC_F23, KC_F24, KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO, KC_NO, OSM(MOD_MEH), KC_TRNS, KC_TRNS, KC_LCTL, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO),
	[4] = NULL_LAYER, [5] = NULL_LAYER, [6] = NULL_LAYER, [7] = NULL_LAYER, [8] = NULL_LAYER, [9] = NULL_LAYER, [10] = NULL_LAYER, [11] = NULL_LAYER, [12] = NULL_LAYER, [13] = NULL_LAYER, [14] = NULL_LAYER, [15] = LAYOUT(RESET, KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU, RGB_TOG, RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD, RGB_MOD, RGB_RMOD, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_CAPS, KC_SLCK, KC_NLCK, KC_NO, RGB_SAD, RGB_SAI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, RGB_M_P, RGB_M_B, RGB_M_R, RGB_HUI, RGB_HUD, RGB_M_SW, RGB_M_K, RGB_M_X, RGB_M_G)
};
// clang-format on
