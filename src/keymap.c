#include QMK_KEYBOARD_H

#include "keymap.h"
#include "swapper.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_split_3x6_3(
    // ╭────────┬────────┬────────┬────────┬────────┬────────╮                     ╭────────┬────────┬────────┬────────┬────────┬────────╮
        XXXXXXX ,NO_Q    ,NO_W    ,NO_E    ,NO_R    ,NO_T    ,                      NO_Y    ,NO_U    ,NO_I    ,NO_O    ,NO_P    ,XXXXXXX ,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                     ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,NO_A    ,NO_S    ,NO_D    ,NO_F    ,NO_G    ,                      NO_H    ,NO_J    ,NO_K    ,NO_L    ,NO_OSTR ,XXXXXXX ,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                     ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,NO_Z    ,NO_X    ,NO_C    ,NO_V    ,NO_B    ,                      NO_N    ,NO_M    ,NO_ARNG ,NO_AE   ,XXXXXXX ,MO(CFG) ,
    // ╰────────┴────────┴────────┴────────┼────────┼────────┼────────╮   ╭────────├────────┼────────┼────────┴────────┴────────┴────────╯
                                            XXXXXXX ,XXXXXXX ,LA_NAV  ,    LA_NUMS ,XXXXXXX ,XXXXXXX
    //                                     ╰────────┴────────┴────────╯   ╰────────┴────────┴────────╯
    ),
    [NAV] = LAYOUT_split_3x6_3(
    // ╭────────┬────────┬────────┬────────┬────────┬────────╮                     ╭────────┬────────┬────────┬────────┬────────┬────────╮
        XXXXXXX ,XXXXXXX ,XXXXXXX ,SW_PTAB ,SW_NTAB ,KC_CAPS ,                      KC_ESC  ,KC_PGDN ,KC_PGUP ,TR_JMPF ,TR_JMPB ,XXXXXXX ,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                     ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,OS_ALT  ,OS_GUI  ,OS_CTRL ,OS_SHFT ,TR_COPY ,                      KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,XXXXXXX ,XXXXXXX ,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                     ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,EMOJI   ,SW_WIN  ,SW_APP  ,TR_TMUX ,TR_PAST ,                      KC_TAB  ,KC_HOME ,KC_END  ,TR_WCTR ,TR_WGRW ,MO(CFG) ,
    // ╰────────┴────────┴────────┴────────┼────────┼────────┼────────╮   ╭────────├────────┼────────┼────────┴────────┴────────┴────────╯
                                            XXXXXXX ,XXXXXXX ,KC_TRNS ,    LA_NUME ,XXXXXXX ,XXXXXXX
    //                                     ╰────────┴────────┴────────╯   ╰────────┴────────┴────────╯
    ),
    [NUM] = LAYOUT_split_3x6_3(
    // ╭────────┬────────┬────────┬────────┬────────┬────────╮                     ╭────────┬────────┬────────┬────────┬────────┬────────╮
        XXXXXXX ,XXXXXXX ,NO_7    ,NO_8    ,NO_9    ,NO_COMM ,                      NO_CIRC ,NO_TILD ,NO_ACUT ,NO_GRV  ,XXXXXXX ,XXXXXXX ,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                     ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,XXXXXXX ,NO_4    ,NO_5    ,NO_6    ,NO_DOT  ,                      KC_BSPC ,OS_SHFT ,OS_CTRL ,OS_RGUI ,OS_ALT  ,XXXXXXX ,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                     ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,XXXXXXX ,NO_1    ,NO_2    ,NO_3    ,NO_0    ,                      XXXXXXX ,NO_CLON ,XXXXXXX ,XXXXXXX ,XXXXXXX ,MO(CFG) ,
    // ╰────────┴────────┴────────┴────────┼────────┼────────┼────────╮   ╭────────├────────┼────────┼────────┴────────┴────────┴────────╯
                                            XXXXXXX ,XXXXXXX ,KC_TRNS ,    KC_TRNS ,XXXXXXX ,XXXXXXX
    //                                     ╰────────┴────────┴────────╯   ╰────────┴────────┴────────╯
    ),
    [SYM] = LAYOUT_split_3x6_3(
    // ╭────────┬────────┬────────┬────────┬────────┬────────╮                     ╭────────┬────────┬────────┬────────┬────────┬────────╮
        XXXXXXX ,XXXXXXX ,NO_HASH ,NO_DQOU ,NO_QUES ,NO_EXLM ,                      NO_AMPR ,NO_LPAR ,NO_RPAR ,NO_SLSH ,XXXXXXX ,XXXXXXX ,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                     ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,NO_DLR  ,NO_ASTR ,NO_QUOT ,NO_SEMI ,NO_MINS ,                      NO_EQL  ,NO_LCBR ,NO_RCBR ,NO_PIPE ,XXXXXXX ,XXXXXXX ,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                     ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,NO_PERC ,NO_LABK ,NO_RABK ,NO_PLUS ,NO_USCR ,                      NO_AT   ,NO_LBRC ,NO_RBRC ,NO_BLSH ,XXXXXXX ,MO(CFG) ,
    // ╰────────┴────────┴────────┴────────┼────────┼────────┼────────╮   ╭────────├────────┼────────┼────────┴────────┴────────┴────────╯
                                            XXXXXXX ,XXXXXXX ,KC_TRNS ,    KC_TRNS ,XXXXXXX ,XXXXXXX
    //                                     ╰────────┴────────┴────────╯   ╰────────┴────────┴────────╯
    ),
    [CFG] = LAYOUT_split_3x6_3(
    // ╭────────┬────────┬────────┬────────┬────────┬────────╮                     ╭────────┬────────┬────────┬────────┬────────┬────────╮
        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,QK_BOOT ,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                     ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                     ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_TRNS ,
    // ╰────────┴────────┴────────┴────────┼────────┼────────┼────────╮   ╭────────├────────┼────────┼────────┴────────┴────────┴────────╯
                                            XXXXXXX ,XXXXXXX ,KC_TRNS ,    KC_TRNS ,XXXXXXX ,XXXXXXX
    //                                     ╰────────┴────────┴────────╯   ╰────────┴────────┴────────╯
    ),
};
// clang-format on

bool sw_app_active = false;
bool sw_win_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  update_swapper(&sw_app_active, KC_LGUI, KC_TAB, SW_APP, keycode, record);
  update_swapper(&sw_win_active, KC_LGUI, NO_LABK, SW_WIN, keycode, record);

  switch (keycode) {
    case LA_NUMS:
      // A little trick to not repeat space when layer key is held.
      if (record->tap.count && record->event.pressed) {
        tap_code(KC_SPC);
        return false;
      }
      break;
  }

  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, NAV, NUM, SYM);
}
