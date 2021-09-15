/* Copyright 2020 Boardsource
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

#include "../../../../../indianboy42/keymap_common.h"

// TODO: WIP
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
    KENT(X)            \
    KLSFT(X)           \
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
    KSCLN(X)           \
    KLCTL(X)           \
    KLGUI(X)           \
    KLGUI(X)           \
    KLALT(X)           \
    KSYM(X)            \
    KSPC(X)            \
    KSSYM(X)           \
    KLEFT(X)           \
    KDOWN(X)           \
    KMO15(X)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {IB42_LAYER_TABLE(X_KEYMAP_ARRAY)};
