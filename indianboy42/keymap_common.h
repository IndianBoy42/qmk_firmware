#pragma once

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
#define X_SFTLYR_10(L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, ...) LLSFT(10),
#define X_SFTLYR_11(L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, ...) LLSFT(11),
#define X_SFTLYR_12(L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, ...) LLSFT(12),
#define X_SFTLYR_13(L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, ...) LLSFT(13),
#define X_SFTLYR_14(L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, ...) LLSFT(14),
#define X_SFTLYR_15(L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15, ...) LLSFT(15),

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define X_MO(ID, ...) MO(ID)
#define X_LT(ID, ALT, ...) LT(ID, ALT)
#define X_LM(ID, ALT, MODS, ...) LM(ID, MODS)
#define IB42_LAYER_TABLE(X)                        \
    X(BASE___, X__LAYER_0, X_MO, NO_ALT, MOD_NONE) \
    X(SYMBOLS, X__LAYER_1, X_MO, NO_ALT, MOD_NONE) \
    X(LSFTSYM, X_SFTLYR_1, X_MO, NO_ALT, MOD_NONE) \
    X(LSF2SYM, X__LAYER_1, X_LM, NO_ALT, MOD_LSFT) \
    X(ENTCMBO, X__LAYER_2, X_LT, KC_ENT, MOD_NONE) \
    X(TABNAVI, X__LAYER_3, X_LT, KC_TAB, MOD_NONE) \
    X(KBDMGMT, X__LAYER_4, X_MO, NO_ALT, MOD_NONE)

#ifndef KBD_MAPPING
#    define KBD_MAPPING()
#endif
#define X_ID_NAME(NAME) ID_LAYER_##NAME
#define X_ID_ENUM(NAME, ...) X_ID_NAME(NAME),
#define X_LAYOUT_HELPER(...) LAYOUT(__VA_ARGS__)
#define X_KEYMAP_ARRAY(NAME, XMACRO, ...) [X_ID_NAME(NAME)] = X_LAYOUT_HELPER(KBD_MAPPING(XMACRO)),
#define X_KC_ENUM(NAME, XMACRO, KC, ALT, MODS) KC_##NAME = KC(X_ID_NAME(NAME), ALT, MODS),

#if 1
enum { IB42_LAYER_TABLE(X_ID_ENUM) };
enum { IB42_LAYER_TABLE(X_KC_ENUM) };
#else
enum { ID_LAYER_BASE = 0, ID_LAYER_SYMBOLS, ID_LAYER_ENTCMBO, ID_LAYER_TABNAVI, ID_LAYER_KBDMGMT };

#    define KEYMAP_BASE(TABLE) [ID_LAYER_BASE] = TABLE(X__LAYER_0)
#    define KC_BASE MO(ID_LAYER_BASE)

#    define KEYMAP_SYMBOLS(TABLE) [ID_LAYER_SYMBOLS] = TABLE(X__LAYER_1)
#    define KC_SYMBOLS MO(ID_LAYER_SYMBOLS)
#    define KC_LSFTSYM LM(ID_LAYER_SYMBOLS, MOD_LSFT)

#    define KEYMAP_ENTCMBO(TABLE) [ID_LAYER_ENTCMBO] = TABLE(X__LAYER_2)
#    define KC_ENTCMBO LT(ID_LAYER_ENTCMBO, KC_ENT)

#    define KEYMAP_TABNAVI(TABLE) [ID_LAYER_TABNAVI] = TABLE(X__LAYER_3)
#    define KC_TABNAVI LT(ID_LAYER_TABNAVI, KC_TAB)

#    define KEYMAP_KBDMGMT(TABLE) [ID_LAYER_KBDMGMT] = TABLE(X__LAYER_4)
#    define KC_KBDMGMT MO(ID_LAYER_KBDMGMT)
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// clang-format off
//                            BASE,           SYMBOLS,       ENTCMBO,     TABNAVI,            KBDMGMT,
#define KESC(X)             X(KC_GESC,        KC_GRV,        _,           LCS(KC_ESC),        RESET) 
#define KLBRC(X)            X(KC_LBRC,        _,             _,           _,                  _)
#define KRBRC(X)            X(KC_RBRC,        _,             _,           _,                  _)
#define KBSLS(X)            X(KC_BSLS,        _,             _,           _,                  _)
#define KDEL(X)             X(KC_DEL,         _,             _,           LSA(KC_F),          RGB_MOD) 
#define KBSPC(X)            X(KC_BSPC,        _,             _,           KC_BSPC,            RGB_RMOD) 
#define KTAB(X)             X(KC_TABNAVI,     KC_1,          _,           _,                  KC_F1) 
#define KSCLN(X)            X(KC_SCLN,        KC_MINS,       _,           KC_NO,              KC_F11) 
#define KQUOT(X)            X(KC_QUOT,        KC_EQL,        _,           KC_NO,              KC_F12) 
#define KENT(X)             X(KC_ENTCMBO,     KC_EQL,        _,           LCS(KC_P),          KC_F12) 
#define KLSFT(X)            X(KC_LSFT,        _,             KC_LCA,      KC_NO,              KC_CAPS) 
#define KCOMM(X)            X(KC_COMM,        KC_RBRC,       _,           KC_PGUP,            KC_NO) 
#define KDOT(X)             X(KC_DOT,         KC_BSLS,       _,           KC_END,             KC_NO) 
#define KSLSH(X)            X(KC_SLSH,        _,             _,           KC_END,             KC_NO) 
#define KUP(X)              X(KC_UP,          KC_PGUP,       KC_SLSH,     KC_NO,              KC_NO) 
#define KMO15(X)            X(KC_KBDMGMT,     LCS(KC_P),     _,           KC_NO,              _) 
#define KLCTL(X)            X(KC_LCTL,        _,             KC_HYPR,     OSM(MOD_MEH),       RGB_M_P) 
#define KLGUI(X)            X(KC_LGUI,        _,             KC_SGUI,     _,                  RGB_M_B) 
#define KLALT(X)            X(KC_LALT,        _,             KC_MEH,      _,                  RGB_M_R) 
#define KSYM(X)             X(KC_SYMBOLS,     _,             KC_LCTL,     KC_LCTL,            RGB_HUI) 
#define KSPC(X)             X(KC_SPC,         KC_SPC,        KC_LCS,      KC_LSFT,            RGB_HUD) 
#define KSSYM(X)            X(KC_LSFTSYM,     _,             KC_LCAG,     KC_NO,              RGB_M_SW) 
#define KSLSH2(X)           X(KC_SLSH,        KC_UP,         KC_SLSH,     KC_NO,              KC_NO) 
#define KLEFT2(X)           X(KC_NO,          KC_LEFT,       KC_MEH,      KC_NO,              RGB_M_K) 
#define KDOWN2(X)           X(KC_NO,          KC_DOWN,       KC_SGUI,     KC_NO,              RGB_M_X) 
#define KRGHT2(X)           X(KC_NO,          KC_RGHT,       KC_HYPR,     KC_NO,              RGB_M_G)
#define KLEFT(X)            X(KC_LEFT,        KC_HOME,       KC_MEH,      KC_NO,              RGB_M_K) 
#define KDOWN(X)            X(KC_DOWN,        KC_PGDN,       KC_SGUI,     KC_NO,              RGB_M_X) 
#define KRGHT(X)            X(KC_RGHT,        KC_END,        KC_HYPR,     KC_NO,              RGB_M_G)
#define KQ(X)               X(KC_Q,           LCA(KC_Q),     _,           KC_F13,             KC_MUTE) 
#define KW(X)               X(KC_W,           LCA(KC_W),     _,           KC_F14,             KC_VOLD) 
#define KE(X)               X(KC_E,           LCA(KC_E),     _,           KC_F15,             KC_VOLU) 
#define KR(X)               X(KC_R,           LCA(KC_R),     _,           KC_F16,             KC_BRID) 
#define KT(X)               X(KC_T,           LCA(KC_T),     _,           KC_WH_U,            KC_BRIU) 
#define KY(X)               X(KC_Y,           LCA(KC_Y),     _,           RALT(KC_J),         RGB_TOG) 
#define KU(X)               X(KC_U,           LCA(KC_U),     _,           RALT(KC_K),         RGB_VAI) 
#define KI(X)               X(KC_I,           LCA(KC_I),     _,           LCS(KC_TAB),        RGB_VAD) 
#define KO(X)               X(KC_O,           LCA(KC_O),     _,           LCTL(KC_TAB),       RGB_SPI) 
#define KP(X)               X(KC_P,           KC_INS,        _,           KC_PSCR,            RGB_SPD) 
#define KA(X)               X(KC_A,           KC_2,          _,           KC_F17,             KC_F2) 
#define KS(X)               X(KC_S,           KC_3,          _,           KC_F18,             KC_F3) 
#define KD(X)               X(KC_D,           KC_4,          _,           KC_F19,             KC_F4) 
#define KF(X)               X(KC_F,           KC_5,          _,           KC_F20,             KC_F5) 
#define KG(X)               X(KC_G,           KC_6,          _,           KC_WH_D,            KC_F6) 
#define KH(X)               X(KC_H,           KC_7,          _,           KC_LEFT,            KC_F7) 
#define KJ(X)               X(KC_J,           KC_8,          _,           KC_DOWN,            KC_F8) 
#define KK(X)               X(KC_K,           KC_9,          _,           KC_UP,              KC_F9) 
#define KL(X)               X(KC_L,           KC_0,          _,           KC_RGHT,            KC_F10) 
#define KZ(X)               X(KC_Z,           LCA(KC_Z),     _,           KC_F21,             KC_SLCK) 
#define KX(X)               X(KC_X,           LCA(KC_X),     _,           KC_F22,             KC_NLCK) 
#define KC(X)               X(KC_C,           MEH(KC_C),     _,           KC_F23,             KC_NO) 
#define KV(X)               X(KC_V,           MEH(KC_V),     _,           KC_F24,             RGB_SAD) 
#define KB(X)               X(KC_B,           KC_QUOT,       _,           KC_NO,              RGB_SAI) 
#define KN(X)               X(KC_N,           KC_SLSH,       _,           KC_HOME,            KC_NO) 
#define KM(X)               X(KC_M,           KC_LBRC,       _,           KC_PGDN,            KC_NO)
// clang-format on