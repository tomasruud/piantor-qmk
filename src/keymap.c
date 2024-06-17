#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "swapper.h"

#define KC_AE KC_QUOT         // Æ
#define KC_OE KC_SCLN         // Ø
#define KC_AA KC_LBRC         // Å
#define SY_LCBR S(A(KC_8))    // {
#define SY_RCBR S(A(KC_9))    // }
#define SY_LPAR S(KC_8)       // (
#define SY_RPAR S(KC_9)       // )
#define SY_LBRC A(KC_8)       // [
#define SY_RBRC A(KC_9)       // ]
#define SY_LT KC_GRV          // <
#define SY_GT S(KC_GRV)       // >
#define SY_BLSH S(A(KC_7))    // Backslash
#define SY_PIPE A(KC_7)       // |
#define SY_SLSH S(KC_7)       // /
#define SY_TLDE A(KC_RBRC)    // ~
#define SY_SQTE KC_NUBS       // '
#define SY_DQTE S(KC_2)       // "
#define SY_HASH S(KC_3)       // #
#define SY_AT KC_BSLS         // @
#define SY_DLR S(KC_4)        // $
#define SY_DASH KC_SLSH       // -
#define SY_USCR S(KC_SLASH)   // _
#define SY_CLON S(KC_DOT)     // :
#define SY_SEMI LSFT(KC_COMM) // ;
#define SY_COMM KC_COMM       // ,
#define SY_DOT KC_DOT         // .
#define SY_BTCK               // `
#define SY_TCK                // ´
#define SY_EQL                // =
#define SY_PLUS               // +
#define SY_QUES               // ?
#define SW_NTAB C(KC_TAB)     // Next tab
#define SW_PTAB C(S(KC_TAB))  // Prev tab
#define EMOJI G(C(KC_SPC))    // Emoji
#define LA_SYM MO(SYM)        // Symbol layer
#define LA_NAV MO(NAV)        // Navigation layer
#define LA_NUM MO(NUM)        // Number layer

enum keycodes {
  // Custom oneshot mod implementation with no timers.
  OS_SHFT = SAFE_RANGE,
  OS_CTRL,
  OS_ALT,
  OS_CMD,

  SW_APP, // Switch to next app (cmd-tab)
  SW_WIN, // Switch to next window (cmd-')
};

enum layers {
  DEF,
  NAV,
  SYM,
  NUM,
  CFG,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_split_3x6_3(
    // ╭────────┬────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────┬────────╮
        XXXXXXX ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,    KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,XXXXXXX ,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,    KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_AE   ,XXXXXXX ,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,    KC_N    ,KC_M    ,XXXXXXX ,KC_OE   ,KC_AA   ,XXXXXXX ,
    // ╰────────┴────────┴────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┴────────┴────────╯
                                   XXXXXXX ,LA_NAV  ,KC_LSFT ,    KC_SPC  ,LA_SYM  ,XXXXXXX
    //                            ╰────────┴────────┴────────╯   ╰────────┴────────┴────────╯
    ),

    [NAV] = LAYOUT_split_3x6_3(
    // ╭────────┬────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────┬────────╮
        XXXXXXX ,SW_APP  ,SW_WIN  ,SW_PTAB ,SW_NTAB ,KC_VOLU ,    KC_ESC  ,KC_HOME ,KC_END  ,KC_BRIU ,KC_BRID ,XXXXXXX ,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,OS_SHFT ,OS_CTRL ,OS_ALT  ,OS_CMD  ,KC_VOLD ,    KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,KC_BSPC ,XXXXXXX ,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,EMOJI   ,KC_MPRV ,KC_MPLY ,KC_MNXT ,KC_MUTE ,    KC_TAB  ,KC_PGDN ,KC_PGUP ,XXXXXXX ,KC_ENT  ,XXXXXXX ,
    // ╰────────┴────────┴────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┴────────┴────────╯
                                   XXXXXXX ,KC_TRNS ,KC_LSFT ,    KC_SPC  ,LA_NUM  ,XXXXXXX
    //                            ╰────────┴────────┴────────╯   ╰────────┴────────┴────────╯
    ),

    [SYM] = LAYOUT_split_3x6_3(
    // ╭────────┬────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────┬────────╮
        XXXXXXX ,SY_HASH ,SY_AT   ,SY_LCBR ,SY_RCBR ,....... ,    KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,XXXXXXX ,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,KC_NUHS ,KC_PMNS ,SY_LPAR ,SY_RPAR ,KC_LT   ,    KC_UNDS ,OS_CMD  ,OS_ALT  ,OS_CTRL ,OS_SHFT ,XXXXXXX ,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,KC_PLUS ,KC_QUES ,SY_LBRC ,SY_RBRC ,SY_PIPE ,    KC_NUBS ,KC_RCBR ,KC_LCBR ,KC_RBRC ,KC_LBRC ,XXXXXXX ,
    // ╰────────┴────────┴────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┴────────┴────────╯
                                   XXXXXXX ,LA_NUM  ,KC_LSFT ,    KC_SPC  ,KC_TRNS ,XXXXXXX
    //                            ╰────────┴────────┴────────╯   ╰────────┴────────┴────────╯
    ),

    [SYM_OLD] = LAYOUT_split_3x6_3(
    // ╭────────┬────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────┬────────╮
        XXXXXXX ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_GRV  ,KC_PERC ,    KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,XXXXXXX ,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,KC_NUHS ,KC_PMNS ,KC_PIPE ,KC_GT   ,KC_LT   ,    KC_UNDS ,OS_CMD  ,OS_ALT  ,OS_CTRL ,OS_SHFT ,XXXXXXX ,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,KC_PLUS ,KC_QUES ,KC_BLSH ,KC_EQL  ,KC_PIPE ,    KC_NUBS ,KC_RCBR ,KC_LCBR ,KC_RBRC ,KC_LBRC ,XXXXXXX ,
    // ╰────────┴────────┴────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┴────────┴────────╯
                                   XXXXXXX ,LA_NUM  ,KC_LSFT ,    KC_SPC  ,KC_TRNS ,XXXXXXX
    //                            ╰────────┴────────┴────────╯   ╰────────┴────────┴────────╯
    ),

    [NUM] = LAYOUT_split_3x6_3(
    // ╭────────┬────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────┬────────╮
        XXXXXXX ,KC_P1   ,KC_P2   ,KC_P3   ,KC_P4   ,KC_P5   ,    KC_P6   ,KC_P7   ,KC_P8   ,KC_P9   ,KC_P0   ,XXXXXXX ,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,OS_SHFT ,OS_CTRL ,OS_ALT  ,OS_CMD  ,KC_F11  ,    KC_F12  ,OS_CMD  ,OS_ALT  ,OS_CTRL ,OS_SHFT ,XXXXXXX ,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,    KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,MO(CFG) ,
    // ╰────────┴────────┴────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┴────────┴────────╯
                                   XXXXXXX ,KC_TRNS ,KC_LSFT ,    KC_SPC  ,KC_TRNS ,XXXXXXX
    //                            ╰────────┴────────┴────────╯   ╰────────┴────────┴────────╯
    ),

    [CFG] = LAYOUT_split_3x6_3(
    // ╭────────┬────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────┬────────╮
        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,    XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,QK_BOOT ,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,    XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,    XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_TRNS ,
    // ╰────────┴────────┴────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┴────────┴────────╯
                                   XXXXXXX ,KC_TRNS ,XXXXXXX ,    XXXXXXX ,KC_TRNS ,XXXXXXX
    //                            ╰────────┴────────┴────────╯   ╰────────┴────────┴────────╯
    ),
};
// clang-format on

bool is_oneshot_cancel_key(uint16_t keycode) {
  switch (keycode) {
  case LA_SYM:
  case LA_NAV:
    return true;
  default:
    return false;
  }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
  switch (keycode) {
  case LA_SYM:
  case LA_NAV:
  case KC_LSFT:
  case OS_SHFT:
  case OS_CTRL:
  case OS_ALT:
  case OS_CMD:
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  update_swapper(&sw_app_active, KC_LGUI, KC_TAB, SW_APP, keycode, record);
  update_swapper(&sw_win_active, KC_LGUI, SY_SQTE, SW_WIN, keycode, record);

  update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
  update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
  update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
  update_oneshot(&os_cmd_state, KC_LCMD, OS_CMD, keycode, record);

  return true;
}
