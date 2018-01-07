/* 


This has some tricks to do stuff.  
 
	- atomic/keymaps/pvc/keymap.c
	- ergodox_ez/keymaps/drashna <- these have a symbol layer similar to what I want
	- TODO: look at the ergodox editor to see if it will export this kind of thing

	- This is how to get the shifted keys:
		- https://docs.qmk.fm/feature_advanced_keycodes.html#shifted-keycodes







 */

#include "preonic.h"
#include "action_layer.h"

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT
};

enum tab_dance{
	TD_ANGLE_BRACKET=0,
	TD_CURLY_BRACE,
	TD_BRACKET,
	TD_PAREN,
	TD_QUOTE
};

qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_ANGLE_BRACKET] = ACTION_TAP_DANCE_DOUBLE( KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET ),
	[TD_CURLY_BRACE]   = ACTION_TAP_DANCE_DOUBLE( KC_LEFT_CURLY_BRACE,   KC_RIGHT_CURLY_BRACE   ),
	[TD_BRACKET]       = ACTION_TAP_DANCE_DOUBLE( KC_LBRACKET,           KC_RBRACKET            ),
	[TD_PAREN]         = ACTION_TAP_DANCE_DOUBLE( KC_LEFT_PAREN,         KC_RIGHT_PAREN         ),
	[TD_QUOTE]         = ACTION_TAP_DANCE_DOUBLE( KC_DOUBLE_QUOTE,       KC_QUOTE               )
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  | Del  |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   Q  |   W  |   E  |   R  |   T  | Bksp |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+------+-------------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  | Enter|   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------+------+------|------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |ALT(B)| Tab  |   N  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LEFT | UP   | DOWN | RIGHT| Lower| Spac | Shift| Raise| OS   |      |      |      |
 * `-----------------------------------------------------------------------------------'

KC_LALT - Alt
KC_LGUI - Windows
 */
[_QWERTY] = {
  {KC_ESC,  KC_1,    KC_2,    KC_3,     KC_4,    KC_5,        KC_DEL,   KC_6,        KC_7,    KC_8,    KC_9,    KC_0   },
  {KC_GRV,  KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,        KC_BSPC,  KC_Y,        KC_U,    KC_I,    KC_O,    KC_P   },
  {KC_TAB,  KC_A,    KC_S,    KC_D,     KC_F,    KC_G,        KC_ENT,   KC_H,        KC_J,    KC_K,    KC_L,    KC_SCLN},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,    CTL_T(KC_B), KC_TAB,   ALT_T(KC_N), KC_M,    KC_COMM, KC_DOT,  KC_SLSH},
  {KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT, LOWER,   KC_SPC,      KC_LSFT,  RAISE,       KC_LGUI, KC_SPC,  KC_SPC,  KC_SPC }
},







/* Raise

This is the functionality to allow multiple keys to do multiple things.

	https://docs.qmk.fm/feature_tap_dance.html


 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |      |   ^  |   &  |   *  |   -  |  ;   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  <   |  {   |   [  |  (   |  "   |      |   =  |      |   /  |   +  |  ;   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  ~   |  _   |  \   |  `   |      |      |      |   |  |   ,  |   .  |  ?   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
 {_______,KC_F1,                 KC_F2,               KC_F3,          KC_F4,        KC_F5,        _______, KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10},
 {_______,KC_EXLM,               KC_AT,               KC_HASH,        KC_DLR,       KC_PERC,      _______, KC_CIRC, KC_AMPR,  KC_ASTR,  KC_MINUS, KC_COLON},
 {_______,TD(TD_ANGLE_BRACKET),  TD(TD_CURLY_BRACE),  TD(TD_BRACKET), TD(TD_PAREN), TD(TD_QUOTE), _______, KC_EQUAL, _______, KC_SLASH, KC_PLUS,  KC_SCOLON},
 {_______,KC_TILD,               KC_UNDERSCORE,       KC_BSLASH,      KC_GRAVE,     _______,      _______, _______,  KC_PIPE, KC_COMMA, KC_DOT,  KC_SLSH},
 {_______,_______,               _______,             _______,        _______,      _______,      _______, _______, _______,   _______,  _______,  _______}
},






/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},


/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
  {_______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL},
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______,  _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            PORTE &= ~(1<<6);
          } else {
            unregister_code(KC_RSFT);
            PORTE |= (1<<6);
          }
          return false;
          break;
      }
    return true;
};
