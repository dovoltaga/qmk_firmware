#pragma once

#include "quantum.h"

//#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif

/*
 * ┌───┌───┬───┬───┬───┐
 * │   │01 │02 │03 │04 │
 * │   ├───┼───┼───┼───┤
 * │   │11 │12 │13 │   │
 * ├───┼───┼───┼───┤14 │
 * │20 │21 │22 │23 │   │
 * ├───┼───┼───┼───┼───┤
 * │30 │30 │31 │32 │   │
 * ├───┼───┴───┼───┤33 │
 * │40 │41     │43 │   │
 * └───┴───────┴───┴───┘
 */

#define LAYOUT_numpad_4x5_3( \
         K01, K02, K03, K04, \
         K11, K12, K13, K14, \
    K20, K21, K22, K23,      \
    K30, K31, K32, K33, K34, \
    K40, K41,      K43       \
  ) \
  { \
    { KC_NO, K01, K02,   K03, K04   }, \
    { KC_NO, K11, K12,   K13, K14   }, \
    { K20,   K21, K22,   K23, KC_NO }, \
    { K30,   K31, K32,   K33, K34   }, \
    { K40,   K41, KC_NO, K43, KC_NO }  \
  }
#define LAYOUT LAYOUT_numpad_4x5_3

