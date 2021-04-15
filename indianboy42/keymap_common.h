#pragma once

#define KEY_ESC_0 KC_GESC
#define KEY_ESC_1 KC_GESC

#define _ KC_TRNS
#define LCS(...) LCTL(LSFT(__VA_ARGS__))
#define KC_LCS C_S_T(OSM(MOD_LCTL | MOD_LSFT))
#define KC_LCA LCA(KC_NO)
#define KC_LCAG LCAG(KC_NO)
#define KC_MEH MEH(KC_NO)
#define KC_SGUI SGUI(KC_NO)
#define KC_HYPR HYPR(KC_NO)
#define SMO(X) LM(X, MOD_LSFT)

enum { ID_LAYER_BASE = 0, ID_LAYER_SYMBOLS, ID_LAYER_ENTCMBO, ID_LAYER_TABNAVI, ID_LAYER_KBDMGMT };

#define LC_BASE MO(ID_LAYER_BASE)
#define LC_SYMBOLS MO(ID_LAYER_SYMBOLS)
#define LC_LSFTSYM LM(ID_LAYER_SYMBOLS, MOD_LSFT)
#define LC_ENTCMBO LT(ID_LAYER_ENTCMBO, KC_ENT)
#define LC_TABNAVI LT(ID_LAYER_TABNAVI, KC_TAB)
#define LC_KBDMGMT MO(ID_LAYER_KBDMGMT)

// clang-format off
// NAME, BASE, SYMBOLS, ENTER(COMBOMODS), TAB(NAVI)
#define IB42_LAYOUT(X) \
X(ESC,  KC_GESC,    KC_GRV,    _,       LCS(KC_ESC),  _, _, _, _, _, _, _, _, _, _, _, RESET) \
X(Q  ,  KC_Q,       LCA(KC_Q), _,       KC_F13,       _, _, _, _, _, _, _, _, _, _, _, KC_MUTE) \
X(W,    KC_W,       LCA(KC_W), _,       KC_F14,       _, _, _, _, _, _, _, _, _, _, _, KC_VOLD) \
X(E,    KC_E,       LCA(KC_E), _,       KC_F15,       _, _, _, _, _, _, _, _, _, _, _, KC_VOLU) \
X(R,    KC_R,       LCA(KC_R), _,       KC_F16,       _, _, _, _, _, _, _, _, _, _, _, KC_BRID) \
X(T,    KC_T,       LCA(KC_T), _,       KC_WH_U,      _, _, _, _, _, _, _, _, _, _, _, KC_BRIU) \
X(Y,    KC_Y,       LCA(KC_Y), _,       RALT(KC_J),   _, _, _, _, _, _, _, _, _, _, _, RGB_TOG) \
X(U,    KC_U,       LCA(KC_U), _,       RALT(KC_K),   _, _, _, _, _, _, _, _, _, _, _, RGB_VAI) \
X(I,    KC_I,       LCA(KC_I), _,       LCS(KC_TAB),  _, _, _, _, _, _, _, _, _, _, _, RGB_VAD) \
X(O,    KC_O,       LCA(KC_O), _,       LCTL(KC_TAB), _, _, _, _, _, _, _, _, _, _, _, RGB_SPI) \
X(P,    KC_P,       KC_INS,    _,       KC_PSCR,      _, _, _, _, _, _, _, _, _, _, _, RGB_SPD) \
X(DEL,  KC_DEL,     _,         _,       LSA(KC_F),    _, _, _, _, _, _, _, _, _, _, _, RGB_MOD) \
X(BSPC, KC_BSPC,    _,         _,       KC_BSPC,      _, _, _, _, _, _, _, _, _, _, _, RGB_RMOD) \
X(TAB,  LC_TABNAVI, KC_1,      _,       _,            _, _, _, _, _, _, _, _, _, _, _, KC_F1) \
X(A,    KC_A,       KC_2,      _,       KC_F17,       _, _, _, _, _, _, _, _, _, _, _, KC_F2) \
X(S,    KC_S,       KC_3,      _,       KC_F18,       _, _, _, _, _, _, _, _, _, _, _, KC_F3) \
X(D,    KC_D,       KC_4,      _,       KC_F19,       _, _, _, _, _, _, _, _, _, _, _, KC_F4) \
X(F,    KC_F,       KC_5,      _,       KC_F20,       _, _, _, _, _, _, _, _, _, _, _, KC_F5) \
X(G,    KC_G,       KC_6,      _,       KC_WH_D,      _, _, _, _, _, _, _, _, _, _, _, KC_F6) \
X(H,    KC_H,       KC_7,      _,       KC_LEFT,      _, _, _, _, _, _, _, _, _, _, _, KC_F7) \
X(J,    KC_J,       KC_8,      _,       KC_DOWN,      _, _, _, _, _, _, _, _, _, _, _, KC_F8) \
X(K,    KC_K,       KC_9,      _,       KC_UP,        _, _, _, _, _, _, _, _, _, _, _, KC_F9) \
X(L,    KC_L,       KC_0,      _,       KC_RGHT,      _, _, _, _, _, _, _, _, _, _, _, KC_F10) \
X(SCLN, KC_SCLN,    KC_MINS,   _,       KC_NO,        _, _, _, _, _, _, _, _, _, _, _, KC_F11) \
X(ENT,  LC_ENTCMBO, KC_EQL,    _,       LCS(KC_P),    _, _, _, _, _, _, _, _, _, _, _, KC_F12) \
X(LSFT, KC_LSFT,    _,         KC_LCA,  KC_NO,        _, _, _, _, _, _, _, _, _, _, _, KC_CAPS) \
X(Z,    KC_Z,       LCA(KC_Z), _,       KC_F21,       _, _, _, _, _, _, _, _, _, _, _, KC_SLCK) \
X(X,    KC_X,       LCA(KC_X), _,       KC_F22,       _, _, _, _, _, _, _, _, _, _, _, KC_NLCK) \
X(C,    KC_C,       MEH(KC_C), _,       KC_F23,       _, _, _, _, _, _, _, _, _, _, _, KC_NO) \
X(V,    KC_V,       MEH(KC_V), _,       KC_F24,       _, _, _, _, _, _, _, _, _, _, _, RGB_SAD) \
X(B,    KC_B,       KC_QUOT,   _,       KC_NO,        _, _, _, _, _, _, _, _, _, _, _, RGB_SAI) \
X(N,    KC_N,       KC_SLSH,   _,       KC_HOME,      _, _, _, _, _, _, _, _, _, _, _, KC_NO) \
X(M,    KC_M,       KC_LBRC,   _,       KC_PGDN,      _, _, _, _, _, _, _, _, _, _, _, KC_NO) \
X(COMM, KC_COMM,    KC_RBRC,   _,       KC_PGUP,      _, _, _, _, _, _, _, _, _, _, _, KC_NO) \
X(DOT,  KC_DOT,     KC_BSLS,   _,       KC_END,       _, _, _, _, _, _, _, _, _, _, _, KC_NO) \
X(UP,   KC_UP,      KC_PGUP,   KC_SLSH, KC_NO,        _, _, _, _, _, _, _, _, _, _, _, KC_NO) \
X(MO15, LC_KBDMGMT, LCS(KC_P), _,       KC_NO,        _, _, _, _, _, _, _, _, _, _, _, _) \
X(LCTL, KC_LCTL,    _,         KC_HYPR, OSM(MOD_MEH), _, _, _, _, _, _, _, _, _, _, _, RGB_M_P) \
X(LGUI, KC_LGUI,    _,         KC_SGUI, _,            _, _, _, _, _, _, _, _, _, _, _, RGB_M_B) \
X(LALT, KC_LALT,    _,         KC_MEH,  _,            _, _, _, _, _, _, _, _, _, _, _, RGB_M_R) \
X(SYM,  LC_SYMBOLS, _,         KC_LCTL, KC_LCTL,      _, _, _, _, _, _, _, _, _, _, _, RGB_HUI) \
X(SPC,  KC_SPC,     KC_SPC,    KC_LCS,  KC_LSFT,      _, _, _, _, _, _, _, _, _, _, _, RGB_HUD) \
X(SSYM, LC_LSFTSYM, _,         KC_LCAG, KC_NO,        _, _, _, _, _, _, _, _, _, _, _, RGB_M_SW) \
X(LEFT, KC_LEFT,    KC_HOME,   KC_MEH,  KC_NO,        _, _, _, _, _, _, _, _, _, _, _, RGB_M_K) \
X(DOWN, KC_DOWN,    KC_PGDN,   KC_SGUI, KC_NO,        _, _, _, _, _, _, _, _, _, _, _, RGB_M_X) \
X(RGHT, KC_RGHT,    KC_END,    KC_HYPR, KC_NO,        _, _, _, _, _, _, _, _, _, _, _, RGB_M_G)
// clang-format on

#define X_LAYER_0 (NAME, L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15, ...) L0
#define X_LAYER_1 (NAME, L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15, ...) L1
#define X_LAYER_2 (NAME, L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15, ...) L2
#define X_LAYER_3 (NAME, L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15, ...) L4
#define X_LAYER_4 (NAME, L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15, ...) L4
#define X_LAYER_5 (NAME, L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15, ...) L5
#define X_LAYER_6 (NAME, L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15, ...) L6
#define X_LAYER_7 (NAME, L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15, ...) L7
#define X_LAYER_8 (NAME, L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15, ...) L8
#define X_LAYER_9 (NAME, L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15, ...) L9
#define X_LAYER_10(NAME, L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15, ...) L10
#define X_LAYER_11(NAME, L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15, ...) L11
#define X_LAYER_12(NAME, L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15, ...) L12
#define X_LAYER_13(NAME, L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15, ...) L13
#define X_LAYER_14(NAME, L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15, ...) L14
#define X_LAYER_15(NAME, L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, L14, L15, ...) L15