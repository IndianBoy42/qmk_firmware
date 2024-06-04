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
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _QWERTYP,
    _HANDDOWNN,
    _HANDDOWNR,
    _MINECRAFT,
    _NAV,
    _NUM,
    _NUM2,
    _SYM,
    _HOLY,
    _HOLY2,
    _FUNCTION,
};

#define CSA(A) MEH(A)
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
#define KC_CSA CSA(KC_NO) // TODO: Use one shot mod
#define KC_SGUI SGUI(KC_NO)
#define KC_HYPR HYPR(KC_NO)
#define SMO(X) LM(X, MOD_LSFT)

bool custom_keys(uint16_t keycode, const keyrecord_t *record);
enum custom_keycodes {
    KC_DUMMY_CUSTOM = SAFE_RANGE,
    KC_QU,
    KC_Qu,
    KC_TH,
    KC_CH,
    KC_SH,
    KC_WH,
    KC_GH,
    KC_PH,
    KC_LTEQ,
    KC_GTEQ,
    KC_NTEQ,
    KC_PLEQ,
    KC_MNEQ,
    KC_STEQ,
    KC_SLEQ,
    KC_ARRW,
    KC_LFT_TH,
    KC_RGT_TH,
    LR_PRN, // Sends L and R and place the cursor inside
    LR_CBR,
    LR_BRC,
    LR_TRI,
    LR_QUO,
    LR_DQU,
    LR_GRV,
    // TODO: magic key for closing brackets/parens?
    KR_PRN, // Sends R and move the cursor left (inside)
    KR_CBR,
    KR_BRC,
    KR_TRI,
    KR_QUO,
    KR_DQU,
    KR_GRV,
    KC_ARROW,
};

// Aliases for readability
#define QWERTY DF(_QWERTY)
#define HANDDWN DF(_HANDDOWNN)
#define MINCRFT TO(_MINECRAFT)

#define SYM MO(_SYM)
#define HOLY MO(_HOLY)
#define NUM MO(_NUM)
#define NAV MO(_NAV)
#define FKEYS MO(_FUNCTION)

#define CC_LEFT LCTL(KC_LEFT)
#define CC_DOWN LCTL(KC_DOWN)
#define CC_UP LCTL(KC_UP)
#define CC_RGHT LCTL(KC_RGHT)
#define AL_LEFT LALT(KC_LEFT)
#define AL_DOWN LALT(KC_DOWN)
#define AL_UP LALT(KC_UP)
#define AL_RGHT LALT(KC_RGHT)

#define KC_S_Q LSFT(KC_Q)
#define KC_S_Z LSFT(KC_Z)

#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define CTL_DEL MT(MOD_LCTL, KC_DEL)
#define CST_ESC MT(MOD_LCTL | MOD_LSFT, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ESC MT(MOD_LALT, KC_ESC)
#define ALT_DEL MT(MOD_LALT, KC_DEL)
#define ALT_BSP MT(MOD_LALT, KC_BSPC)
#define SFT_BSP MT(MOD_LSFT, KC_BSPC)
#define SFT_ESC MT(MOD_LSFT, KC_ESC)
#define GUI_ESC MT(MOD_LGUI, KC_ESC)
#define GUI_Q MT(MOD_LGUI, KC_Q)
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
#define CTL_BSP MT(MOD_LCTL, KC_BSPC)
#define SYM_ENT LT(_SYM, KC_ENT)
#define SYM_TAB LT(_SYM, KC_TAB)
#define HLY_TAB LT(_HOLY, KC_TAB)
#define KR_CSYM LT(_HOLY, KC_R)
#define NUM_DEL LT(_NUM, KC_DEL)
#define NUM_ENT LT(_NUM, KC_ENT)
#define NUM_TAB LT(_NUM, KC_TAB)
#define NUM_BSP LT(_NUM, KC_BSPC)
#define NUM_ESC LT(_NUM, KC_ESC)
#define NAV_ENT LT(_NAV, KC_ENT)
#define NAV_SPC LT(_NAV, KC_SPC)
#define NAV_TAB LT(_NAV, KC_TAB)
#define NAV_UND LT(_NAV, KC_UNDS)
#define NAV_BSL LT(_NAV, KC_BSLS)
#define NAV_ESC LT(_NAV, KC_ESC)
#define NAV_DEL LT(_NAV, KC_DEL)
#define NAV_BSP LT(_NAV, KC_BSPC)
#define HOLY_R LT(_HOLY, KC_R)
#define HOLY_SP LT(_HOLY, KC_SPC)
#define CSA_ESC MT(MOD_LCTL | MOD_LSFT | MOD_LALT, KC_ESC)
#define CSA_BSP MT(MOD_LCTL | MOD_LSFT | MOD_LALT, KC_BSPC)
#define KC_COPY LCTL(KC_C)
#define KC_CUT LCTL(KC_X)
#define KC_PSTE LCTL(KC_V)
#define KC_UNDO LCTL(KC_Z)
#define KC_REDO LCTL(LSFT(KC_Z))

#define GU_A MT(MOD_LGUI, KC_A)
#define AL_S MT(MOD_LALT, KC_S)
#define CT_D MT(MOD_LCTL, KC_D)
#define NV_F LT(_NAV, KC_F)
#define GU_SCLN MT(MOD_LGUI, KC_SCLN)
#define AL_L MT(MOD_LALT, KC_L)
#define CT_K MT(MOD_LCTL, KC_K)
#define NV_J LT(_NAV, KC_J)
#define GU_R MT(MOD_LGUI, KC_R)
#define AL_S MT(MOD_LALT, KC_S)
#define CT_N MT(MOD_LCTL, KC_N)
#define NV_T LT(_NAV, KC_T)
#define GU_H MT(MOD_LGUI, KC_H)
#define AL_I MT(MOD_LALT, KC_I)
#define CT_E MT(MOD_LCTL, KC_E)
#define NV_A LT(_NAV, KC_A)

#define TAPTAP(KC, HOLD)                                   \
    case LT(0, KC):                                        \
        if (!record->tap.count && record->event.pressed) { \
            tap_code16(HOLD);                              \
            return false;                                  \
        }                                                  \
        return true;
#define TTKC(KC, HOLD) LT(0, KC)

// TODO: https://docs.qmk.fm/#/feature_key_overrides?id=key-overrides
// Use Key overrides
#define C_SHIFT(X, A, B) X(shift_##A##_##B, ko_make_basic(MOD_MASK_SHIFT, A, B))
#define KEY_OVERRIDE_TABLE(X)    \
    C_SHIFT(X, KC_DOT, KC_CIRC)  \
    C_SHIFT(X, KC_COMM, KC_AMPR) \
    C_SHIFT(X, KC_MINS, KC_PPLS) \
    C_SHIFT(X, KC_EQL, KC_ASTR)  \
    C_SHIFT(X, KC_LPRN, KC_RPRN) \
    C_SHIFT(X, KC_LCBR, KC_RCBR) \
    C_SHIFT(X, KC_LBRC, KC_RBRC) \
    C_SHIFT(X, KC_RPRN, KC_LPRN) \
    C_SHIFT(X, KC_RCBR, KC_LCBR) \
    C_SHIFT(X, KC_RBRC, KC_LBRC) \
    C_SHIFT(X, KC_UNDS, KC_MINS) \
    C_SHIFT(X, KC_CIRC, KC_AMPR) \
    C_SHIFT(X, KC_DLR, KC_PIPE)  \
    C_SHIFT(X, KC_QU, KC_Qu)
#define X_DEF(A, B) const key_override_t A = B;
#define X_LIST(A, B) &A,
KEY_OVERRIDE_TABLE(X_DEF)
const key_override_t **key_overrides = (const key_override_t *[]){
    KEY_OVERRIDE_TABLE(X_LIST) NULL // Null terminate the array of overrides!
};

#define COMBOS_TABLE(X) \
    COMBOS_HANDDOWN(X)  \
    COMBOS_QWERTY(X)    \
    COMBOS_SYM(X)
// TODO: Some of these could be adaptive keys?
#define COMBOS_HANDDOWN(X)         \
    X(1, KC_EQL, KC_COMM, KC_ASTR) \
    X(2, KC_COMM, KC_DOT, KC_CIRC) \
    X(3, KC_DOT, KC_QUOT, KC_AMPR) \
    X(4, KC_QUOT, KC_UNDS, KC_GRV) \
    X(5, KC_SCLN, KC_A, KC_COLN)   \
    X(6, KC_A, KC_E, KC_RBRC)      \
    X(7, KC_E, KC_I, KC_EXLM)      \
    X(8, KC_I, KC_H, KC_DLR)       \
    X(9, KC_SLSH, KC_U, KC_BSLS)   \
    X(10, KC_LPRN, KC_R, LR_PRN)   \
    X(11, KC_LCBR, KC_X, LR_CBR)   \
    X(12, KC_U, KC_O, KC_Q)        \
    X(13, KC_O, KC_Y, KC_QU)       \
    X(14, KC_Y, KC_K, KC_Z)        \
    COMBOS_HANDDOWN_BIGRAM(X)

#define COMBOS_HANDDOWN_BIGRAM(X)        \
    X(15, KC_T, KC_N, KC_LBRC) /*KC_TH*/ \
    X(16, KC_S, KC_N, KC_SH)             \
    X(17, KC_S, KC_T, KC_CH)             \
    X(18, KC_C, KC_L, KC_CH)             \
    X(19, KC_F, KC_P, KC_WH)             \
    X(20, KC_G, KC_D, KC_GH)             \
    X(21, KC_P, KC_M, KC_PH)

// TODO: clean this up
#define COMBOS_QWERTY(X)            \
    X(22, KC_LPRN, KC_A, LR_PRN)    \
    X(23, KC_LCBR, KC_Z, LR_CBR)    \
    X(26, KC_M, KC_COMM, KC_LT)     \
    X(27, KC_M, KC_DOT, KC_GT)      \
    X(28, KC_A, KC_S, KC_SLSH)      \
    X(29, KC_S, KC_D, KC_ASTR)      \
    X(30, KC_D, KC_F, KC_DLR)       \
    X(31, KC_Z, KC_X, KC_AT)        \
    X(32, KC_X, KC_C, KC_HASH)      \
    X(33, KC_C, KC_V, KC_AMPR)      \
    X(37, KC_J, KC_K, KC_UNDS)      \
    X(38, KC_K, KC_L, KC_EQL)       \
    X(39, KC_L, KC_SCLN, KC_EXLM)   \
    X(41, KC_I, KC_O, KC_MINS)      \
    X(43, KC_COMM, KC_DOT, KC_UNDS) \
    X(44, KC_DOT, KC_QUOT, KC_GRV)  \
    X(45, KC_EQL, KC_W, KC_QU)      \
    X(46, KC_EQL, KC_S, KC_Q)       \
    X(47, KC_UNDS, KC_X, KC_Z)
#define COMBOS_SYM(X)               \
    X(48, KC_UNDS, KC_QUOT, LR_QUO) \
    X(49, KC_CIRC, KC_DQUO, LR_DQU) \
    X(50, KC_GRV, KC_LPRN, LR_GRV)  \
    X(51, KC_LBRC, KC_HASH, LR_BRC) \
    X(52, KC_LT, KC_GT, LR_TRI)

#define ADAPTIVE_KEYS_DEF()    \
    AK_SND_ONLY_START(KC_G)    \
    R_SND(KC_M, KC_L)          \
    AK_SND_ONLY_START(KC_U)    \
    R_SND(KC_H, KC_A)          \
    AK_SND_ONLY_START(KC_A)    \
    R_SND(KC_H, KC_U)          \
    AK_SND_ONLY_START(KC_E)    \
    R_SND(KC_H, KC_O)          \
    AK_SND_ONLY_START(KC_B)    \
    R_SND(KC_D, KC_L)          \
    AK_SND_ONLY_START(KC_P)    \
    R_SND(KC_M, KC_L)          \
    AK_SND_ONLY_START(KC_O)    \
    R_SND(KC_H, KC_E)          \
    AK_SND_ONLY_START(KC_QUOT) \
    R_SND(KC_QUOT, KR_QUO)     \
    AK_SND_ONLY_START(KC_DQUO) \
    R_SND(KC_DQUO, KR_DQU)     \
    AK_SND_ONLY_START(KC_GRV)  \
    R_SND(KC_GRV, KR_GRV)      \
    AK_SND_ONLY_START(KC_LPRN) \
    R_SND(KC_RPRN, KR_PRN)     \
    R_SND(KC_F, KR_PRN)        \
    AK_SND_ONLY_START(KC_LBRC) \
    R_SND(KC_RBRC, KR_BRC)     \
    AK_SND_ONLY_START(KC_LCBR) \
    R_SND(KC_RCBR, KR_CBR)     \
    R_SND(KC_V, KR_CBR)        \
    AK_SND_ONLY_START(KC_LT)   \
    R_SND(KC_GT, KR_TRI)
#define ADAPTIVE_KEYS_DONT_WORK \
    AK_BOTH_START(KC_D, KC_D)   \
    R_FST(KC_B, KC_L)           \
    AK_BOTH_START(KC_P, KC_P)   \
    R_SND(KC_M, KC_L)           \
    R_FST(KC_V, KC_L)

#define DANCE_DOUBLE_TAP(N, ...) ACTION_TAP_DANCE_DOUBLE(__VA_ARGS__)
#define DTH_MOD(KC) register_mods(MOD_BIT(KC))
#define DTH_UMOD(KC) unregister_mods(MOD_BIT(KC))
#define DTH_REG(KC) register_code16(MOD_BIT(KC))
#define DTH_UREG(KC) unregister_code16(MOD_BIT(KC))
#define DTH_SEND(STR) SEND_STRING(STR)
#define TAP_DANCE_TABLE(X)                                                              \
    X(ESC_CAP, DANCE_DOUBLE_TAP, NOP, KC_ESC, KC_CAPS)                                  \
    X(DT_PRN, DANCE_DOUBLE_TAP, NOP, KC_LPRN, LR_PRN)                                   \
    X(DT_CBR, DANCE_DOUBLE_TAP, NOP, KC_LCBR, LR_CBR)                                   \
    X(DT_BRC, DANCE_DOUBLE_TAP, NOP, KC_LBRC, LR_BRC)                                   \
    X(DT_TRI, DANCE_DOUBLE_TAP, NOP, KC_LT, LR_TRI)                                     \
    X(DT_QUO, DANCE_DOUBLE_TAP, NOP, KC_QUOT, LR_QUO)                                   \
    X(DT_DQU, DANCE_DOUBLE_TAP, NOP, KC_DQUO, LR_DQU)                                   \
    X(DT_GRV, DANCE_DOUBLE_TAP, NOP, KC_GRV, LR_GRV)                                    \
    X(CTRL_LP, DANCE_TAP_HOLD, DANCE_TAP_HOLD_FNS, KC_LPRN, DTH_MOD, DTH_UMOD, KC_LCTL) \
    X(TH_LPRN, DANCE_TAP_HOLD, DANCE_TAP_HOLD_FNS, KC_LPRN, DTH_SEND, NOP, ")" SS_TAP(X_LEFT))

#define X__NAME(N, ...) _##N
#define X_NAME(N, ...) N
#define X__ENUM(...) X__NAME(__VA_ARGS__),
#define X_ENUM(...) X_NAME(__VA_ARGS__) = TD(X__NAME(__VA_ARGS__)),
enum { TAP_DANCE_TABLE(X__ENUM) TAP_DANCE_TABLE(X_ENUM) };
#define NOP(...)
#define TAP_DANCE_ARR(N, F, G, ...) [X__NAME(N)] = F(N, __VA_ARGS__),
#define TAP_DANCE_FN(N, F, G, ...) G(N, __VA_ARGS__)

// determine the tapdance state to return
static enum {
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_SINGLE_TAP,
} td_state;
int cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            return SINGLE_TAP;
        } else {
            return SINGLE_HOLD;
        }
    }
    if (state->count == 2) {
        return DOUBLE_SINGLE_TAP;
    } else {
        return 3;
    } // any number higher than the maximum state value you return above
}
#define DANCE_TAP_HOLD(N, ...) ACTION_TAP_DANCE_FN_ADVANCED(NULL, N##_finished, N##_reset)
#define DANCE_TAP_HOLD_FNS(N, TAP, HOLD, UNHOLD, ...)              \
    void N##_finished(tap_dance_state_t *state, void *user_data) { \
        td_state = cur_dance(state);                               \
        switch (td_state) {                                        \
            case SINGLE_TAP:                                       \
                register_code16(TAP);                              \
                break;                                             \
            case SINGLE_HOLD:                                      \
                HOLD(__VA_ARGS__);                                 \
                break;                                             \
            case DOUBLE_SINGLE_TAP:                                \
                tap_code16(TAP);                                   \
                register_code16(TAP);                              \
        }                                                          \
    }                                                              \
    void N##_reset(tap_dance_state_t *state, void *user_data) {    \
        switch (td_state) {                                        \
            case SINGLE_TAP:                                       \
                unregister_code16(TAP);                            \
                break;                                             \
            case SINGLE_HOLD:                                      \
                UNHOLD(__VA_ARGS__);                               \
                break;                                             \
            case DOUBLE_SINGLE_TAP:                                \
                unregister_code16(TAP);                            \
        }                                                          \
    }

TAP_DANCE_TABLE(TAP_DANCE_FN)
tap_dance_action_t tap_dance_actions[] = {TAP_DANCE_TABLE(TAP_DANCE_ARR)};

// TODO: Macroize: https://github.com/samhocevar-forks/qmk-firmware/blob/master/docs/feature_tap_dance.md

/* https://github.com/openorclose/qmk_firmware/blob/master/keyboards/crkbd/keymaps/openorclose/features/adaptive_keys.h */
/* https://www.reddit.com/r/KeyboardLayouts/comments/smnv1o/adaptive_keys_qmk_implementation/ */
#include "features/adaptive_keys.h"

// TODO: generate hint strings for the oled automatically
// TODO: try and use alternate hands home-row mod-tap
// or combos for mods/layers (only uncommon ones)
// Ctrl - Alt - Shift - Symbols
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
     KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
     KC_LPRN, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_DEL,
     KC_LCBR, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    NUM_BSP, _______, _______, CTL_DEL, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, FKEYS,
                                GUI_ESC, NAV_TAB, SFT_ENT, SYM,     CTL_ESC, ALT_ENT, NAV_SPC, SFT_TAB, CSA_BSP, KC_ENT
    ),

    [_QWERTYP] = LAYOUT(
     KC_ESC,  KC_EQL,  KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
     KC_LPRN, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_SLSH,
     KC_LCBR, KC_UNDS, KC_X,    KC_C,    KC_V,    KC_B,    NUM_BSP, _______, _______, CTL_DEL, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, FKEYS,
                                GUI_Q,   NAV_TAB, SFT_ENT, SYM,     CTL_ESC, ALT_ENT, NAV_SPC, SFT_TAB, CSA_BSP, KC_ENT
    ),

    [_SYM] = LAYOUT(
     KC_LGUI, KC_GRV,  KC_LPRN, KC_EXLM, KC_PIPE, KC_AT,                                       KC_DQUO, KC_CIRC, KC_QUES, KC_PERC, KC_0,    _______,
     KC_LCTL, KC_LCBR, KC_ASTR, KC_DLR,  KC_RPRN, KC_RCBR,                                     KC_QUOT, KC_UNDS, KC_EQL,  KC_BSLS, KC_COLN, _______,
     KC_LCA,  KC_TILD, KC_LBRC, KC_HASH, KC_AMPR, KC_RBRC, KC_LCTL, _______, _______, KC_LSFT, KC_SLSH, KC_MINS, KC_PPLS, KC_LT,   KC_GT,   KC_Z,
                                _______, _______, _______, _______, _______, KC_LALT, KC_SPC,  KC_LCTL, KC_COMM, KC_DOT
    ),

    [_NUM] = LAYOUT(
     _____,   _____,   _____,   _____,   _____,   _____,                                       KC_LPRN, KC_1,    KC_2,    KC_3,    KC_CIRC, KC_RPRN,
     KC_HYPR, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_CSA,                                      KC_PAST, KC_4,    KC_5,    KC_6,    KC_PSLS, KC_EQL,
     _____,   _____,   _____,   _____,   _____,   _____,   _______, _______, _______, _______, KC_PPLS, KC_7,    KC_8,    KC_9,    KC_PMNS, KC_UNDS,
                                _______, _______, _______, KC_LCTL, KC_LALT, _______, KC_SPC,  KC_0,    KC_COMM, KC_DOT
    ),

    [_NUM2] = LAYOUT(
     ______,  KC_PAST, KC_PSLS, KC_PPLS, KC_PMNS, ______,                                      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_BSPC,
     KC_HYPR, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_CSA,                                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_GT,   KC_LT,
     ______,  KC_CIRC, KC_LPRN, KC_RPRN, KC_UNDS, ______,  _______, _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
                                _______, _______, _______, KC_LCTL, KC_LALT, _______, _______, ____,    KC_COMM, KC_DOT
    ),

    [_NAV] = LAYOUT(
     _____,   KC_UNDO,  KC_CUT, KC_COPY, KC_PSTE, KC_REDO,                                     CC_LEFT, CC_DOWN, CC_UP,   CC_RGHT, KC_MENU, _______,
     _____,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_CSA,                                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,  _______,
     _____,   KC_F1,   AL_LEFT, AL_RGHT,   KC_F2, KC_INS,  _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
                                _______, _______, _______, KC_SPC,  _______, _______, _______, _______, _______, _______
    ),

    // TODO: https://sites.google.com/alanreiser.com/handsdown/home/hands-down-neu#h.ze4kq734zl5w
       // TODO: concentrate on 3 thumb keys for "downgrading" in the future
    [_HANDDOWNN] = LAYOUT(
     NUM_ESC, KC_W,    KC_G,    KC_M,    KC_P,    KC_V,                                        KC_EQL,  KC_COMM, KC_DOT,  KC_QUOT, KC_UNDS, KC_BSPC,
     KC_LPRN, KC_R,    KC_S,    KC_N,    KC_T,    KC_B,                                        KC_SCLN, KC_A,    KC_E,    KC_I,    KC_H,    KC_J,
     KC_LCBR, KC_X,    KC_C,    KC_L,    KC_D,    KC_F,    ALT_BSP, _______, _______, CTL_DEL, KC_SLSH, KC_U,    KC_O,    KC_Y,    KC_K,    FKEYS,
                                KC_LGUI, NAV_TAB, SFT_ENT, HOLY,    CTL_ESC, ALT_ENT, NAV_SPC, SFT_TAB, CSA_BSP, KC_ENT
    ),
    [_HANDDOWNR] = LAYOUT(
     NUM_ESC, KC_X,    KC_P,    KC_H,    KC_G,    KC_K,                                        KC_EQL,  KC_COMM, KC_DOT,  KC_QUOT, KC_UNDS, KC_BSPC,
     KC_LPRN, KC_C,    KC_S,    KC_N,    KC_T,    KC_J,                                        KC_SCLN, KC_A,    KC_E,    KC_I,    KC_M,    KC_DEL,
     KC_LCBR, KC_B,    KC_F,    KC_L,    KC_D,    KC_V,    ALT_BSP, _______, _______, CTL_DEL, KC_SLSH, KC_U,    KC_O,    KC_Y,    KC_W,    FKEYS,
                                KC_LGUI, NAV_TAB, SFT_ENT, HOLY_R,  CTL_ESC, ALT_ENT, NAV_SPC, SFT_TAB, CSA_BSP, KC_ENT
    ),

    [_HOLY] = LAYOUT(
     KC_GRV,  KC_PMNS, KC_PPLS, KC_EXLM, KC_PIPE, KC_AT,                                       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_DEL,
     KC_PERC, KC_CIRC, KC_AMPR, KC_DLR,  KC_LCBR, KC_RCBR,                                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_0,    KC_EQL,
     _______, KC_TILD, KC_BSLS, KC_HASH, KC_LBRC, KC_RBRC, _______, _______, _______, _______, KC_LT,   KC_GT,   KC_6,    KC_7,    KC_8,    KC_9,
                                KC_LGUI, KC_LPRN, KC_RPRN, _______, _______, _______, KC_SPC,  _______, KC_PAST, KC_PSLS
    ),
    [_HOLY2] = LAYOUT(
     KC_GRV,  ____,    KC_AT,   KC_EXLM, KC_LT,   KC_GT,                                       _______, KC_1,    KC_2,    KC_3,    KC_PPLS,  KC_BSPC,
     KC_PERC, KC_CIRC, KC_AMPR, KC_DLR,  KC_LCBR, KC_RCBR,                                     KC_0,    KC_4,    KC_5,    KC_6,    KC_BSLS,  KC_DEL,
     _______, KC_TILD, KC_PIPE, KC_HASH, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_PMNS,  KC_EQL,
                                KC_LGUI, KC_LPRN, KC_RPRN, _______, _______, _______, KC_SPC,  _______, KC_PAST, KC_PSLS
    ),

    [_MINECRAFT] = LAYOUT(
     KC_2,    KC_3,    KC_4,    KC_E,    KC_5,    KC_6,                                        _,       _,       _,       _,       _,       _______,
     KC_1,    KC_LSFT, KC_S,    KC_D,    KC_F,    KC_7,                                        _,       _,       _,       _,       _,       MINCRFT,
     KC_0,    KC_LCTL, KC_X,    KC_C,    KC_9,    KC_8,    KC_T,    _______, _______, ______,  _,       _,       _,       _,       _,       FKEYS,
                                _______, KC_LCTL, KC_LSFT, KC_SPC,  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
    ),

    [_FUNCTION] = LAYOUT(
     QK_BOOT, KC_PAUS, KC_MPLY, KC_MNXT, KC_MPRV, MINCRFT,                                     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   QK_BOOT,
     _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, HANDDWN,                                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PSCR,
     KC_CSA,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  QWERTY,  RGB_TOG, _______, _______, KC_MUTE, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______,
                                KC_NUM,  KC_CAPS, KC_SCRL, RGB_MOD, KC_HYPR, KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20
    )

//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

// TODO: achordion and try home row mods again
// https://getreuer.info/posts/keyboards/achordion/index.html
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TH_LPRN: return DOUBLE_TAP_TERM;
        default:
            return TAPPING_TERM;
    }
}

#undef X_NAME
#define X_NAME(N, ...) COMBO_##N // ##_##B
#undef X_ENUM
#define X_ENUM(N, A, B, C) X_NAME(N, A, B, C),
#define X_name(N, A, B, C) combo_##N // ##_##B
#define X_SEQ(N, A, B, C) const uint16_t PROGMEM X_name(N, A, B, C)[] = {A, B, COMBO_END};
#define X_COMBO(N, A, B, C) [X_NAME(N, A, B, C)] = COMBO(X_name(N, A, B, C), C),

enum combos { COMBOS_TABLE(X_ENUM) };
COMBOS_TABLE(X_SEQ)
combo_t key_combos[] = {COMBOS_TABLE(X_COMBO)};

#define KC_MACRO(KC, STR)            \
case KC:                         \
    if (record->event.pressed) { \
        SEND_STRING(STR);        \
        return false;            \
    }                            \
    break;
#define KC_MACRO2(KC, STR, SSTR) \
case KC:                         \
    if (record->event.pressed) { \
        if ((mods | oneshot_mods) & MOD_MASK_SHIFT && !caps_word) {\
            del_oneshot_mods(MOD_MASK_SHIFT); \
            unregister_mods(MOD_MASK_SHIFT); \
            SEND_STRING(SSTR);        \
            register_mods(mods); \
            return false;            \
        }else{\
            if (caps_word) register_mods(MOD_LSFT); \
            SEND_STRING(STR);        \
            register_mods(mods); \
            return false;            \
        }                            \
    } \
    break;
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    /* Disable combo `SOME_COMBO` on layer `_LAYER_A` */
    switch (combo_index) {
#define ONLY_IN_QWERTY(N, ...)          \
        case X_NAME(N):                     \
            if (!layer_state_is(_QWERTY) && !layer_state_is(_QWERTYP)) { \
                return false;               \
            };                              \
            break;
#define ONLY_IN_HANDDOWN(N, ...)           \
        case X_NAME(N):                        \
            if (!layer_state_is(_HANDDOWNN)) { \
                return false;                  \
            };                                 \
            break;

        COMBOS_QWERTY(ONLY_IN_QWERTY)
        COMBOS_HANDDOWN(ONLY_IN_HANDDOWN)
    }
    return true;
}
bool custom_keys(uint16_t keycode, const keyrecord_t *record) {
    const uint8_t mods = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();
    const uint8_t caps_word = is_caps_word_on();
    switch (keycode) {
        KC_MACRO2(KC_QU, "qu", "Qu") // TODO: send q if ctl/alt/gui?
        KC_MACRO(KC_Qu, "Qu")
        KC_MACRO(KC_TH, "th")
        KC_MACRO(KC_CH, "ch")
        KC_MACRO(KC_SH, "sh")
        KC_MACRO(KC_WH, "wh")
        KC_MACRO(KC_GH, "gh")
        KC_MACRO(KC_PH, "ph")
        KC_MACRO2(KC_LTEQ, "<=", "<<")
        KC_MACRO2(KC_GTEQ, ">=", ">>")
        KC_MACRO2(KC_NTEQ, "!=", "==")
        KC_MACRO2(KC_PLEQ, "+=", "*=")
        KC_MACRO2(KC_MNEQ, "-=", "/=")
        KC_MACRO2(KC_STEQ, "*=", "+=")
        KC_MACRO2(KC_SLEQ, "/=", "-=")
        KC_MACRO2(KC_ARRW, "->", "=>")
#define KC_PAIR(N, L, R) \
        KC_MACRO2(LR_##N, L R SS_TAP(X_LEFT), L "  " R SS_TAP(X_LEFT) SS_TAP(X_LEFT)) \
        KC_MACRO2(KR_##N,  R SS_TAP(X_LEFT),  " " R SS_TAP(X_LEFT) SS_TAP(X_LEFT))
        KC_PAIR(PRN, "(", ")")
        KC_PAIR(CBR, "{", "}")
        KC_PAIR(BRC, "[", "]")
        KC_PAIR(TRI, "<", ">")
        KC_PAIR(QUO, "'", "'")
        KC_PAIR(DQU, "\"", "\"")
        KC_PAIR(GRV, "`", "`")
    }

    return true;
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_adaptive_key(keycode, record)) {
        return false;
    }
    // Everything above here doesn't work with macros
    if (!custom_keys(keycode, record)) {
        return false;
    }

    return true;
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
