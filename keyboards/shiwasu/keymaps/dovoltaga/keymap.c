#include QMK_KEYBOARD_H

#include "keymap_jp.h"

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

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

enum custom_keycodes {
  RGBRST = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_split_3x6_4( \
   KC_ESC,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
   KC_LCTL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, JP_COLN, \
   KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_LGUI, JP_ZKHK, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, \
                                      KC_LALT, LOWER,   KC_SPC,  JP_HENK, RAISE,   FKEY \
),

[_LOWER] = LAYOUT_split_3x6_4( \
  _______,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   JP_AT, \
  _______, _______, _______, _______, _______, _______,                   JP_MINS, JP_CIRC, JP_YEN , _______, JP_SCLN, JP_COLN, \
  _______, _______, _______, _______, _______, _______, _______, _______, JP_LBRC, JP_RBRC, KC_COMM, KC_DOT , KC_SLSH, JP_BSLS, \
                                      _______, _______, _______, _______, _______, _______  \
),

[_RAISE] = LAYOUT_split_3x6_4(\
  _______, JP_EXLM, JP_DQUO, JP_HASH, JP_DLR,  JP_PERC,                   JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN, _______, JP_GRV, \
  _______, _______, _______, _______, _______, _______,                   JP_EQL,  JP_TILD, JP_PIPE, _______, JP_PLUS, JP_ASTR, \
  _______, _______, _______, _______, _______, _______, _______, _______, JP_LCBR, JP_RCBR, JP_LABK, JP_RABK, JP_QUES, JP_UNDS, \
                                      _______, _______, _______, _______, _______, _______ \
),

[_FKEY] = LAYOUT_split_3x6_4(\
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,                   KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, KC_DEL, \
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_TAB,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_CAPS, _______, JP_KANA, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, KC_INS, \
                                      _______, _______, _______, JP_MHEN, _______, _______ \
),

[_ADJUST] = LAYOUT_split_3x6_4(\
  _______, RESET,   RGBRST,  _______, _______, _______,                   _______, _______, _______, _______, _______, KC_DEL, \
  _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                      _______, _______, _______, _______, _______, _______  \
)

};

int RGB_current_mode;

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}
