#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _NUMPAD 0
#define _ADJUST 1

#define NLKADJ LT(_ADJUST,KC_NLCK)

enum custom_keycodes {
  RGBRST = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_NUMPAD] = LAYOUT_numpad_4x5_3(\
	     NLKADJ,  KC_PSLS, KC_PAST, KC_PMNS,	\
             KC_P7,   KC_P8,   KC_P9,   KC_PPLS, \
    KC_PSCR, KC_P4,   KC_P5,   KC_P6,		 \
    KC_SLCK, KC_P1,   KC_P2,   KC_P3,   KC_PENT, \
    KC_PAUS, KC_P0,            KC_PDOT		 \

),
[_ADJUST] =  LAYOUT_numpad_4x5_3(\
             _______, RESET,   _______, _______,\
	     _______, _______, _______, _______,\
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,         \
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______,\
    RGBRST,  _______,          _______          \
)

};

int RGB_current_mode;

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
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
