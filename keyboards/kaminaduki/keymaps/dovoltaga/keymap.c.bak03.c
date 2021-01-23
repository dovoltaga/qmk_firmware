#include QMK_KEYBOARD_H

#include "keymap_jp.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FKEY 3
#define _ADJUST 4

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define FKEY   MO(_FKEY)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  :   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  UP  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | FKEY | ZKHK |  OS  | ALT  |Lower | Space| HENK |Raise | FKEY | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
   KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
   KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, JP_COLN, \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_ENT, \
   FKEY,    JP_ZKHK, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  JP_HENK, RAISE,   FKEY,    KC_LEFT, KC_DOWN, KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | TAB  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  @   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |   `  |   |  |   ~  |   =  |   -  |   ^  |   \  |      |   ;  |  :   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |   ?  |   _  |   {  |   }  |  [   |   ]  |  ,   |  .   |  /   |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    JP_AT, \
  _______, _______, JP_GRV,  JP_PIPE, JP_TILD, JP_EQL,  JP_MINS, JP_CIRC, JP_YEN , _______, JP_SCLN, JP_COLN, \
  _______, _______, JP_QUES, JP_UNDS, JP_LCBR, JP_RCBR, JP_LBRC, JP_RBRC, KC_COMM, KC_DOT , KC_SLSH, JP_BSLS, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | TAB  |  !   |  "   |  #   |  $   |  %   |  &   |   '  |  (   |  )   |      |  `   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |  @   |  \   |  ^   |  -   |  =   |   ~  |   |  |      |   +  |  *   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |  /   |  \   |  [   |  ]   |  {   |   }  |   <  |   >  |   ?  |  _   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_TAB,  JP_EXLM, JP_DQUO, JP_HASH, JP_DLR,  JP_PERC, JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN, _______, JP_GRV, \
  _______, _______, JP_AT,   JP_YEN,  JP_CIRC, JP_MINS, JP_EQL,  JP_TILD, JP_PIPE, _______, JP_PLUS, JP_ASTR, \
  _______, _______, JP_SLSH, JP_BSLS, JP_LBRC, JP_RBRC, JP_LCBR, JP_RCBR, JP_LABK, JP_RABK, JP_QUES, JP_UNDS, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* FKEY
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | F11  | DEL  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | CAPS |  1   |  2   |  3   |  4   |  5   |  Pus | PSc  | HOME | PgUp | F12  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  6   |  7   |  8   |  9   |  0   |      | ScrLk| END  | PgDn | Shift| INS  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  .   |      |      |      | MHEN | KANA |      |      | DEL  |  OS  | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_FKEY] = LAYOUT_ortho_4x12( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_DEL, \
  KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PAUS, KC_PSCR, KC_HOME, KC_PGUP, KC_F12,  _______, \
  _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, KC_SLCK, KC_END,  KC_PGDN, KC_RSFT, KC_INS, \
  _______, KC_DOT, _______, _______, _______,  JP_MHEN, JP_KANA, _______, _______, KC_DEL,  KC_RGUI, KC_RCTL \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |RGBVAI|RGBVAD|RGBTOG|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, RGB_VAI, RGB_VAD, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  #ifdef RGBLIGHT_ENABLE
    switch (get_highest_layer(state)) {
    case _LOWER:
      //rgblight_sethsv_at(HSV_BLUE, 0);
      rgblight_sethsv(HSV_BLUE);
      break;
    case _RAISE:
      //rgblight_sethsv_at(HSV_RED, 0);
      rgblight_sethsv(HSV_RED);
      break;
    case _FKEY:
      //rgblight_sethsv_at(HSV_YELLOW, 0);
      rgblight_sethsv(HSV_YELLOW);
      break;
    default: //  for any other layers, or the default layer
      //rgblight_sethsv_at( 0, 0, 0, 0);
      rgblight_sethsv( 0, 0, 0);
      break;
    }
    //rgblight_set_effect_range( 1, 1);
#endif
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}
