#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base layer
    [0] = LAYOUT_split_3x6_3(KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U,
                             KC_I, KC_O, KC_P, KC_LBRC, KC_NO, KC_A, KC_S, KC_D,
                             KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,
                             KC_QUOT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N,
                             KC_M, KC_PCMM, KC_PDOT, KC_LT, KC_NO, KC_NO, MO(1),
                             KC_LSFT, KC_SPC, MO(2), KC_NO),

    // Navigation layer
    [1] = LAYOUT_split_3x6_3(KC_NO, LGUI(KC_TAB), LGUI(KC_GRV), KC_BRID,
                             KC_BRIU, KC_VOLU, KC_ESC, KC_HOME, KC_END, KC_NO,
                             KC_NO, KC_NO, KC_NO, OSM(MOD_LSFT), OSM(MOD_LCTL),
                             OSM(MOD_LALT), OSM(MOD_LGUI), KC_VOLD, KC_LEFT,
                             KC_DOWN, KC_UP, KC_RGHT, KC_BSPC, KC_NO, KC_NO,
                             KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_TAB,
                             KC_PGDN, KC_PGUP, KC_NO, KC_ENT, KC_NO, KC_NO,
                             KC_TRNS, KC_LSFT, KC_SPC, MO(3), KC_NO),

    // Symbol layer
    [2] = LAYOUT_split_3x6_3(
        KC_NO, KC_EXLM, KC_AT, KC_HASH, KC_GRV, KC_PERC, KC_CIRC, KC_AMPR,
        KC_ASTR, KC_LPRN, KC_RPRN, KC_NO, KC_NO, KC_NUHS, KC_PMNS, LALT(KC_7),
        KC_GT, KC_LT, KC_UNDS, OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL),
        OSM(MOD_LSFT), KC_NO, KC_NO, KC_PLUS, KC_QUES, LSA(KC_7), KC_EQL,
        KC_PIPE, KC_NUBS, LSA(KC_8), LSA(KC_9), LALT(KC_8), LALT(KC_9), KC_NO,
        KC_NO, MO(3), KC_LSFT, KC_SPC, KC_TRNS, KC_NO),

    // Number layer
    [3] = LAYOUT_split_3x6_3(KC_NO, KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, KC_P6,
                             KC_P7, KC_P8, KC_P9, KC_P0, KC_NO, KC_NO,
                             OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT),
                             OSM(MOD_LGUI), KC_F11, KC_F12, OSM(MOD_LGUI),
                             OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT), KC_NO,
                             KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
                             KC_F7, KC_F8, KC_F9, KC_F10, MO(4), KC_NO, KC_TRNS,
                             KC_LSFT, KC_SPC, KC_TRNS, KC_NO),

    // Boot layer
    [4] = LAYOUT_split_3x6_3(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                             KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT, KC_NO, KC_NO,
                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                             KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS,
                             KC_NO)};
