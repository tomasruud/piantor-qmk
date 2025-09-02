#include QMK_KEYBOARD_H

#include "keymap.h"
#include "oneshot.h"
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
        XXXXXXX ,OS_ALT  ,OS_CMD  ,OS_CTRL ,OS_SHFT ,TR_COPY ,                      KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,XXXXXXX ,XXXXXXX ,
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
        XXXXXXX ,XXXXXXX ,NO_4    ,NO_5    ,NO_6    ,NO_DOT  ,                      KC_BSPC ,OS_SHFT ,OS_CTRL ,OS_RCMD ,OS_ALT  ,XXXXXXX ,
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

bool is_oneshot_cancel_key(uint16_t keycode) {
  switch (keycode) {
  case KC_ESC:
    return true;
  default:
    return false;
  }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
  switch (keycode) {
  case LA_NUMS:
  case LA_NUME:
  case LA_NAV:
  case KC_LSFT:
  case OS_SHFT:
  case OS_CTRL:
  case OS_ALT:
  case OS_CMD:
  case OS_RCMD:
    return true;
  default:
    return false;
  }
}

bool sw_app_active = false;
bool sw_win_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;
oneshot_state os_rcmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  update_swapper(&sw_app_active, KC_LGUI, KC_TAB, SW_APP, keycode, record);
  update_swapper(&sw_win_active, KC_LGUI, NO_LABK, SW_WIN, keycode, record);

  update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
  update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
  update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
  update_oneshot(&os_cmd_state, KC_LCMD, OS_CMD, keycode, record);
  update_oneshot(&os_rcmd_state, KC_RCMD, OS_RCMD, keycode, record);

  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, NAV, NUM, SYM);
}
