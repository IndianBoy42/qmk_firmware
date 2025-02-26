#pragma once

// TODO: This configuration is jank, just make an external tool for defining keymaps that generates C files

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helper Macros

#define _ KC_TRNS
#define LCS(...) LCTL(LSFT(__VA_ARGS__))
#define KC_LCS C_S_T(OSM(MOD_LCTL | MOD_LSFT))
#define KC_LCA LCA(KC_NO)
#define KC_LCAG LCAG(KC_NO)
#define KC_MEH MEH(KC_NO)
#define KC_SGUI SGUI(KC_NO)
#define KC_HYPR HYPR(KC_NO)
#define SMO(X) LM(X, MOD_LSFT)

enum custom_keycodes {
    KC_DUMMY_CUSTOM = SAFE_RANGE,
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Layer X-Macros

#define X__LAYER_0(L0, ...) L0,
#define X__LAYER_1(L0, L1, ...) L1,
#define X__LAYER_2(L0, L1, L2, ...) L2,
#define X__LAYER_3(L0, L1, L2, L3, ...) L3,
#define X__LAYER_4(L0, L1, L2, L3, L4, ...) L4,
#define X__LAYER_5(L0, L1, L2, L3, L4, L5, ...) L5,
#define X__LAYER_6(L0, L1, L2, L3, L4, L5, L6, ...) L6,
#define X__LAYER_7(L0, L1, L2, L3, L4, L5, L6, L7, ...) L7,
#define X__LAYER_8(L0, L1, L2, L3, L4, L5, L6, L7, L8, ...) L8,
#define X__LAYER_9(L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, ...) L9,
#define X__LAYER_10(L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, ...) L10,
#define X__LAYER_11(L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, ...) L11,
#define X__LAYER_12(L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, ...) L12,
#define X__LAYER_13(L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, ...) L13,
#define X__LAYER_14(L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, ...) L14,
#define X__LAYER_15(L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15, ...) L15,
#define X_SFTLYR_0(L0, ...) LSFT(L0),
#define X_SFTLYR_1(L0, L1, ...) LSFT(L1),
#define X_SFTLYR_2(L0, L1, L2, ...) LSFT(L2),
#define X_SFTLYR_3(L0, L1, L2, L3, ...) LSFT(L3),
#define X_SFTLYR_4(L0, L1, L2, L3, L4, ...) LSFT(L4),
#define X_SFTLYR_5(L0, L1, L2, L3, L4, L5, ...) LSFT(L5),
#define X_SFTLYR_6(L0, L1, L2, L3, L4, L5, L6, ...) LSFT(L6),
#define X_SFTLYR_7(L0, L1, L2, L3, L4, L5, L6, L7, ...) LSFT(L7),
#define X_SFTLYR_8(L0, L1, L2, L3, L4, L5, L6, L7, L8, ...) LSFT(L8),
#define X_SFTLYR_9(L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, ...) LSFT(L9),
#define X_SFTLYR_10(L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, ...) LSFT(10),
#define X_SFTLYR_11(L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, ...) LSFT(11),
#define X_SFTLYR_12(L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, ...) LSFT(12),
#define X_SFTLYR_13(L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, ...) LSFT(13),
#define X_SFTLYR_14(L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, ...) LSFT(14),
#define X_SFTLYR_15(L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15, ...) LSFT(15),

#define X_MO(ID, ...) MO(ID)
#define X_TT(ID, ...) TT(ID)
#define X_OS(ID, ...) OSL(ID)
#define X_LT(ID, ALT, ...) LT(ID, ALT)
#define X_LM(ID, ALT, MODS, ...) LM(ID, MODS)
#define X_ID_NAME(NAME) ID_LAYER_##NAME
#define X_ID_ENUM(NAME, ...) X_ID_NAME(NAME),
#define X_LAYOUT_HELPER(...) LAYOUT(__VA_ARGS__)
#define X_KEYMAP_ARRAY(NAME, XMACRO, ...) [X_ID_NAME(NAME)] = X_LAYOUT_HELPER(KBD_MAPPING(XMACRO)),
#define X_KC_ENUM(NAME, XMACRO, KC, ALT, MODS) KC_##NAME = KC(X_ID_NAME(NAME), ALT, MODS),

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Defining my layers

// Layer Definitions: Name, Keys based on, How to enter (MO,LT), Tap key for LT, Modifier to keep Activated
#define IB42_LAYER_TABLE(X)                        \
    X(BASE___, X__LAYER_0, X_MO, NO_ALT, MOD_NONE) \
    X(SYMBOLS, X__LAYER_1, X_MO, NO_ALT, MOD_NONE) \
    X(LSFTSYM, X__LAYER_1, X_LM, NO_ALT, MOD_LSFT) \
    X(ENTCMBO, X__LAYER_2, X_LT, KC_ENT, MOD_NONE) \
    X(TABNAVI, X__LAYER_3, X_LT, KC_TAB, MOD_NONE) \
    X(ALTSYMS, X__LAYER_4, X_MO, NO_ALT, MOD_NONE) \
    X(ALTNUMS, X__LAYER_5, X_TT, NO_ALT, MOD_NONE) \
    X(ALTSYM2, X__LAYER_6, X_MO, NO_ALT, MOD_NONE) \
    X(KBDMGMT, X__LAYER_7, X_MO, NO_ALT, MOD_NONE)
// X(LSFTSYM, X_SFTLYR_1, X_MO, NO_ALT, MOD_NONE)
// X(ALTSYMS, X__LAYER_4, X_MO, NO_ALT, MOD_NONE)

// #ifndef KBD_MAPPING
// #    define KBD_MAPPING()
// #endif

enum { IB42_LAYER_TABLE(X_ID_ENUM) };
enum { IB42_LAYER_TABLE(X_KC_ENUM) };

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// clang-format off
//                            BASE,           SYMBOLS,       ENTCMBO,     TABNAVI,        ALTSYMS,    ALTNUMS,       ALTSYMS2,   KBDMGMT
#define KESC(X)             X(KC_GESC,        KC_GRV,        _,           LCS(KC_ESC),    KC_GRV,     _,             KC_GRV,     RESET)
#define KQ(X)               X(KC_Q,           LCA(KC_Q),     _,           KC_F13,         KC_ALTNUMS, _,             KC_1,       KC_F1)
#define KW(X)               X(KC_W,           LCA(KC_W),     _,           KC_F14,         KC_LBRC,    KC_PERC,       KC_2,       KC_F2)
#define KE(X)               X(KC_E,           LCA(KC_E),     _,           KC_F15,         KC_EXLM,    KC_PLUS,       KC_3,       KC_F3)
#define KR(X)               X(KC_R,           LCA(KC_R),     _,           KC_F16,         KC_AT,      KC_PMNS,       KC_4,       RGB_TOG)
#define KT(X)               X(KC_T,           LCA(KC_T),     _,           KC_WH_U,        KC_RBRC,    KC_NO,         KC_5,       RGB_VAI)
#define KY(X)               X(KC_Y,           LCA(KC_Y),     _,           RALT(KC_J),     KC_DQUO,    KC_P1,         KC_6,       RGB_VAD)
#define KU(X)               X(KC_U,           LCA(KC_U),     _,           RALT(KC_K),     KC_CIRC,    KC_P2,         KC_7,       RGB_SPD)
#define KI(X)               X(KC_I,           LCA(KC_I),     _,           LCS(KC_TAB),    KC_QUES,    KC_P3,         KC_8,       KC_1)
#define KO(X)               X(KC_O,           LCA(KC_O),     _,           LCTL(KC_TAB),   KC_PERC,    KC_NO,         KC_9,       KC_2)
#define KP(X)               X(KC_P,           KC_INS,        _,           KC_PSCR,        KC_NO,      KC_NO,         KC_0,       KC_3)
#define KDEL(X)             X(KC_DEL,         _,             _,           LSA(KC_F),      _,          _,             KC_MINS,    KC_VOLD)
#define KBSPC(X)            X(KC_BSPC,        _,             _,           KC_BSPC,        _,          _,             KC_PPLS,    KC_VOLU)
#define KTAB(X)             X(KC_TABNAVI,     KC_1,          _,           _,              KC_LCTL,    KC_LCTL,       KC_EXLM,    KC_NO)
#define KA(X)               X(KC_A,           KC_2,          _,           KC_F17,         KC_LPRN,    KC_DLR,        KC_AT,      KC_F4)
#define KS(X)               X(KC_S,           KC_3,          _,           KC_F18,         KC_ASTR,    KC_LPRN,       KC_HASH,    KC_F5)
#define KD(X)               X(KC_D,           KC_4,          _,           KC_F19,         KC_DLR,     KC_RPRN,       KC_DLR,     KC_F6)
#define KF(X)               X(KC_F,           KC_5,          _,           KC_F20,         KC_PIPE,    KC_DOT,        KC_PERC,    RGB_MOD)
#define KG(X)               X(KC_G,           KC_6,          _,           KC_WH_D,        KC_RPRN,    KC_P0,         KC_CIRC,    RGB_RMOD)
#define KH(X)               X(KC_H,           KC_7,          _,           KC_LEFT,        KC_QUOT,    KC_P4,         KC_AMPR,    KC_BRIU)
#define KJ(X)               X(KC_J,           KC_8,          _,           KC_DOWN,        KC_UNDS,    KC_P5,         KC_ASTR,    RGB_SPI)
#define KK(X)               X(KC_K,           KC_9,          _,           KC_UP,          KC_EQL,     KC_P6,         KC_LPRN,    KC_4)
#define KL(X)               X(KC_L,           KC_0,          _,           KC_RGHT,        KC_BSLS,    KC_P0,         KC_RPRN,    KC_5)
#define KSCLN(X)            X(KC_SCLN,        KC_MINS,       _,           KC_NO,          KC_COLN,    KC_NO,         KC_UNDS,    KC_6)
#define KENT(X)             X(KC_ENTCMBO,     KC_EQL,        _,           LCS(KC_P),      KC_SCLN,    KC_NO,         KC_EQL,     KC_0)
#define KLSFT(X)            X(KC_LSFT,        _,             KC_LCA,      KC_NO,          KC_ALTNUMS, _,             KC_ALTNUMS, KC_CAPS)
#define KZ(X)               X(KC_Z,           LCA(KC_Z),     _,           KC_F21,         KC_LCBR,    KC_NO,         KC_LBRC,    KC_F7)
#define KX(X)               X(KC_X,           LCA(KC_X),     _,           KC_F22,         KC_PLUS,      KC_CIRC,     KC_RBRC,    KC_F8)
#define KC(X)               X(KC_C,           MEH(KC_C),     _,           KC_F23,         KC_HASH,    KC_ASTR,       KC_PIPE,    KC_F9)
#define KV(X)               X(KC_V,           MEH(KC_V),     _,           KC_F24,         KC_AMPR,    KC_SLSH,       KC_QUOT,    KC_F10)
#define KB(X)               X(KC_B,           KC_QUOT,       _,           KC_NO,          KC_RCBR,    KC_NO,         KC_DQUO,    KC_F11)
#define KN(X)               X(KC_N,           KC_SLSH,       _,           KC_HOME,        KC_SLSH,    KC_P7,         KC_SLSH,    KC_F12)
#define KM(X)               X(KC_M,           KC_LBRC,       _,           KC_PGDN,        KC_MINS,    KC_P8,         KC_BSLS,    KC_BRID)
#define KCOMM(X)            X(KC_COMM,        KC_RBRC,       _,           KC_PGUP,        KC_LT,      KC_P9,         KC_LCBR,    KC_7)
#define KDOT(X)             X(KC_DOT,         KC_BSLS,       _,           KC_END,         KC_RT,      KC_DOT,        KC_RCBR,    KC_8)
#define KUP(X)              X(KC_UP,          KC_PGUP,       KC_SLSH,     KC_NO,          KC_PGUP,    _,             KC_PGUP,    KC_9)
#define KMO15(X)            X(KC_KBDMGMT,     LCS(KC_P),     _,           KC_NO,          KC_NO,      _,             KC_NO,      _)
#define KLCTL(X)            X(KC_LCTL,        _,             KC_HYPR,     OSM(MOD_MEH),   _,          _,             _,          KC_MUTE)
#define KLGUI(X)            X(KC_LGUI,        _,             KC_SGUI,     _,              _,          _,             _,          RGB_M_P)
#define KLALT(X)            X(KC_LALT,        _,             KC_MEH,      _,              _,          _,             _,          RGB_M_B)
#define KSYM(X)             X(KC_ALTSYMS,     _,             KC_LCTL,     KC_LCTL,        _,          _,             _,          RGB_M_R)
#define KSPC(X)             X(KC_SPC,         KC_SPC,        KC_LCS,      KC_LSFT,        _,          KC_LSFT,       _,          RGB_HUI)
#define KSSYM(X)            X(KC_ALTNUMS,     _,             KC_LCAG,     KC_NO,          _,          _,             KC_RCBR,    RGB_HUD)
#define KLEFT(X)            X(KC_LEFT,        KC_HOME,       KC_MEH,      KC_NO,          KC_HOME,    LSFT(KC_HOME), KC_HOME,    RGB_M_SW)
#define KDOWN(X)            X(KC_DOWN,        KC_PGDN,       KC_SGUI,     KC_NO,          KC_PGDN,    LSFT(KC_PGDN), KC_PGDN,    RGB_M_K)
#define KRGHT(X)            X(KC_RGHT,        KC_END,        KC_HYPR,     KC_NO,          KC_END,     LSFT(KC_END),  KC_END,     RGB_M_G)
#define KSLSH(X)            X(KC_SLSH,        _,             _,           KC_NO,          _,          _,             _,          KC_NO)
#define KVLT(X)             X(KC_LEFT,        KC_HOME,       KC_LCAG,     KC_NO,          KC_HOME,    LSFT(KC_HOME), KC_HOME,    RGB_M_SW)
#define KVDN(X)             X(KC_DOWN,        KC_PGDN,       KC_MEH,      KC_NO,          KC_PGDN,    LSFT(KC_PGDN), KC_PGDN,    RGB_M_K)
#define KVUP(X)             X(KC_UP,          KC_PGUP,       KC_SGUI,     KC_NO,          KC_PGUP,    LSFT(KC_PGUP), KC_PGUP,    RGB_M_X)
#define KVRT(X)             X(KC_RGHT,        KC_END,        KC_HYPR,     KC_NO,          KC_END,     LSFT(KC_END),  KC_END,     RGB_M_G)
#define KNOB(X)             X(KC_ALTSYMS,     _,             KC_LCTL,     KC_LCTL,        _,          _,             _,          RGB_HUI)

#define KRBRC(X)            X(KC_RBRC,        _,             _,           _,              _,          _, _)
#define KQUOT(X)            X(KC_QUOT,        KC_EQL,        _,           KC_NO,          _,          _, KC_F12)
#define KBSLS(X)            X(KC_BSLS,        _,             _,           _,              _,          _, _)
#define K1(X)               X(KC_1,           KC_F1,         _,           _,              _,          _, KC_NO)
#define K2(X)               X(KC_2,           KC_F2,         _,           _,              _,          _, KC_NO)
#define K3(X)               X(KC_3,           KC_F3,         _,           _,              _,          _, KC_NO)
#define K4(X)               X(KC_4,           KC_F4,         _,           _,              _,          _, KC_NO)
#define K5(X)               X(KC_5,           KC_F5,         _,           _,              _,          _, KC_NO)
#define K6(X)               X(KC_6,           KC_F6,         _,           _,              _,          _, KC_NO)
#define K7(X)               X(KC_7,           KC_F7,         _,           _,              _,          _, KC_NO)
#define K8(X)               X(KC_8,           KC_F8,         _,           _,              _,          _, KC_NO)
#define K9(X)               X(KC_9,           KC_F9,         _,           _,              _,          _, KC_NO)
#define K0(X)               X(KC_0,           KC_F10,        _,           _,              _,          _, KC_NO)
#define KMINS(X)            X(KC_MINS,        KC_F11,        _,           _,              _,          _, KC_NO)
#define KEQL(X)             X(KC_EQL,         KC_F12,        _,           _,              _,          _, KC_NO)

#define MTG(X) MT(MOD_LGUI, X)
#define MTA(X) MT(MOD_LALT, X)
#define MTC(X) MT(MOD_LCTl, X)
#define MTS(X) MT(MOD_LSFT, X)
#define KmA(X)              X(MTG(KC_A),      KC_2,          _,           KC_F17,         KC_AMPR,    KC_F2)
#define KaS(X)              X(MTA(KC_S),      KC_3,          _,           KC_F18,         KC_ASTR,    KC_F3)
#define KcD(X)              X(MTC(KC_D),      KC_4,          _,           KC_F19,         KC_DLR,     KC_F4)
#define KsF(X)              X(MTS(KC_F),      KC_5,          _,           KC_F20,         KC_LBRC,    KC_F5)
#define KsH(X)              X(MTS(KC_H),      KC_7,          _,           KC_LEFT,        KC_4,       KC_F7)
#define KcJ(X)              X(MTC(KC_J),      KC_8,          _,           KC_DOWN,        KC_5,       KC_F8)
#define KaK(X)              X(MTA(KC_K),      KC_9,          _,           KC_UP,          KC_6,       KC_F9)
#define KmL(X)              X(MTG(KC_L),      KC_0,          _,           KC_RGHT,        KC_AMPR,    KC_F10)

// clang-format on

// Rotary Encoder Functions
enum { TD_MUSIC_BUTTON };
#define KMUSIC(X) X(TD(0), _, _, _, _, _, _, _)
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [0] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MNXT),
};
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise)
            // tap_code(KC_VOLU);
            tap_code(KC_WH_D);
        else
            // tap_code(KC_VOLD);
            tap_code(KC_WH_U);
    }
    return true;
}
