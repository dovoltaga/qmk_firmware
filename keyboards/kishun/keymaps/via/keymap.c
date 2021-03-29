#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _NUMPAD 0
#define _FN1 1
#define _FN2 2
#define _FN3 3
#define _FN4 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_NUMPAD] = LAYOUT_numpad_4x5_3(\
             KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, \
             KC_P7,   KC_P8,   KC_P9,   KC_PPLS, \
    KC_PSCR, KC_P4,   KC_P5,   KC_P6,		 \
    KC_SLCK, KC_P1,   KC_P2,   KC_P3,   KC_PENT, \
    KC_PAUS, KC_P0,            KC_PDOT		 \

),
[_FN1] =  LAYOUT_numpad_4x5_3(\
             _______, _______, _______, _______,\
	     _______, _______, _______, _______,\
    _______, _______, _______, _______,         \
    _______, _______, _______, _______, _______,\
    _______,  _______,          _______         \
),
[_FN2] =  LAYOUT_numpad_4x5_3(\
             _______, _______, _______, _______,\
	     _______, _______, _______, _______,\
    _______, _______, _______, _______,         \
    _______, _______, _______, _______, _______,\
    _______,  _______,          _______          \
),
[_FN3] =  LAYOUT_numpad_4x5_3(\
             _______, _______, _______, _______,\
	     _______, _______, _______, _______,\
    _______, _______, _______, _______,         \
    _______, _______, _______, _______, _______,\
    _______,  _______,          _______          \
),
[_FN4] =  LAYOUT_numpad_4x5_3(\
             _______, _______, _______, _______,\
	     _______, _______, _______, _______,\
    _______, _______, _______, _______,         \
    _______, _______, _______, _______, _______,\
    _______,  _______,          _______          \
),

};
