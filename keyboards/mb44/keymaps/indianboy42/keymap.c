/* Copyright 2020 melonbred
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
#define LAYOUT(K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K30, K31, K32, K33, K36, K37, K39, K3A, K3B, ...) LAYOUT_2u_space(K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K30, K31, K32, K33, K36, K37, K39, K3A, K3B)
#include "../../../../indianboy42/keymap_common.h"

#define KBD_MAPPING(X) \
    KESC(X)            \
    KQ(X)              \
    KW(X)              \
    KE(X)              \
    KR(X)              \
    KT(X)              \
    KY(X)              \
    KU(X)              \
    KI(X)              \
    KO(X)              \
    KP(X)              \
    KBSPC(X)           \
    KTAB(X)            \
    KA(X)              \
    KS(X)              \
    KD(X)              \
    KF(X)              \
    KG(X)              \
    KH(X)              \
    KJ(X)              \
    KK(X)              \
    KL(X)              \
    KSCLN(X)           \
    KENT(X)            \
    KLSFT(X)           \
    KZ(X)              \
    KX(X)              \
    KC(X)              \
    KV(X)              \
    KB(X)              \
    KN(X)              \
    KM(X)              \
    KCOMM(X)           \
    KDOT(X)            \
    BTM_ROW_TRAD(X)

#define BTM_ROW_TRAD(X) \
    KUP(X)              \
    KMO15(X)            \
    KLCTL(X)            \
    KLGUI(X)            \
    KLALT(X)            \
    KSYM(X)             \
    KSSYM(X)            \
    KSPC(X)             \
    KLEFT(X)            \
    KDOWN(X)            \
    KRGHT(X)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {IB42_LAYER_TABLE(X_KEYMAP_ARRAY)};

// Rotary Encoder Functions
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_WH_D);
        } else {
            tap_code(KC_WH_U);
        }
    }
    return true;
}
