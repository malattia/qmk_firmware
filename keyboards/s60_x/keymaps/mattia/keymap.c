#include "s60_x.h"

#define GRAVE_MODS  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_LALT)|MOD_BIT(KC_RSHIFT)|MOD_BIT(KC_RGUI)|MOD_BIT(KC_RALT))
#define _______ KC_TRNS

enum function_id {
	ESC_GRV,
	H_DELC,
	W_DELW,
	RGBLED_TOGGLE,
	RGBLED_STEP_MODE,
	RGBLED_INCREASE_HUE,
	RGBLED_DECREASE_HUE,
	RGBLED_INCREASE_SAT,
	RGBLED_DECREASE_SAT,
	RGBLED_INCREASE_VAL,
	RGBLED_DECREASE_VAL,
};

/*
 * SpaceFN
 * http://geekhack.org/index.php?topic=51069.0
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Default Layer
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ ESC │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │▒▒▒▒▒│BKSPC│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│ TAB │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │  \  │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│LCTRL│  A  │  S  │  D  │  F  │  G  │ H/Bs│  J  │  K  │  L  │  ;  │  '  │▒▒▒▒▒│ENTER│█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│LSHFT│ Fn0 |  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │▒▒▒▒▒│RSHFT│▒▒▒▒▒│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│LCTRL│L_GUI│L_ALT│█████│█████│█████| Spc |█████│█████│█████│R_ALT│R_GUI│ APP │RCTRL│█████│
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */
    KEYMAP(
      F(ESC_GRV),  KC_1,    KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_NO,     KC_BSPC, \
        KC_TAB  ,  KC_Q,    KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,            \
        KC_LCTL ,  KC_A,    KC_S,     KC_D,     KC_F,     KC_G,     F(H_DELC),KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NO,   KC_ENT,             \
        KC_LSFT ,  MO(1),   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_NO,   KC_RSFT,   KC_NO,   \
        KC_LCTL ,  KC_LGUI, KC_LALT,                                KC_SPACE,                     KC_RALT,  MO(1),    MO(2),    KC_RCTL                      ),

    /* Overlay 1: FN, Vim-movements
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│  `  │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │▒▒▒▒▒│ Del │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │     │     │ Ins │     │     │     │     │     │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │Left │Down │ Up  │Right│     │     │▒▒▒▒▒│     │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │     │     │     │     │     │     │▒▒▒▒▒│     │▒▒▒▒▒│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │█████│█████│█████│     │█████│█████│█████│     │     │     │     │█████│
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */
    KEYMAP(
        KC_GRV ,  KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  ,  KC_F5  ,  KC_F6  ,  KC_F7  ,  KC_F8  ,  KC_F9  ,  KC_F10 ,  KC_F11 ,  KC_F12 ,  _______,  KC_DEL , \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_INS ,  _______,  _______,  _______,  _______,  _______,           \
        _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP  ,  KC_RGHT,  _______,  _______,  _______,  _______,           \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______            ),

    /* Overlay 2: backlight, media keys
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │BlTog│ Bl- │ Bl+ │BlSte│     │     │     │     │     │     │     │     │▒▒▒▒▒│     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │Mute │Vol- │Vol+ │     │     │     │     │     │     │     │     │     │     │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │RGBTo│RGMSt│     │     │     │     │     │     │     │     │     │▒▒▒▒▒│     │█████│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │     │     │     │     │     │     │▒▒▒▒▒│     │▒▒▒▒▒│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │█████│█████│█████│     │█████│█████│█████│     │     │     │     │█████│
└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */
    KEYMAP(
        _______,  BL_TOGG,  BL_DEC ,  BL_INC ,  BL_STEP,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
        _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,           \
        _______,  F(2)   ,  F(3)   ,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,           \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______            ),

};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
	[ 0] = ACTION_FUNCTION(ESC_GRV),
	[ 1] = ACTION_FUNCTION(H_DELC),
	[ 2] = ACTION_FUNCTION(RGBLED_TOGGLE),
	[ 3] = ACTION_FUNCTION(RGBLED_STEP_MODE),
	[ 4] = ACTION_FUNCTION(RGBLED_INCREASE_HUE),
	[ 5] = ACTION_FUNCTION(RGBLED_DECREASE_HUE),
	[ 6] = ACTION_FUNCTION(RGBLED_INCREASE_SAT),
	[ 7] = ACTION_FUNCTION(RGBLED_DECREASE_SAT),
	[ 8] = ACTION_FUNCTION(RGBLED_INCREASE_VAL),
	[ 9] = ACTION_FUNCTION(RGBLED_DECREASE_VAL),
};

void key_if_mod(keyrecord_t *record, uint8_t modbits, uint8_t mod_key, uint8_t key) {
	static uint8_t mods_pressed;

	mods_pressed = get_mods() & modbits;
	void (*fn)(uint8_t) = record->event.pressed ? add_key : del_key;
	if (mods_pressed) {
		fn(mod_key);
	} else {
		fn(key);
	}
	send_keyboard_report();
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
	switch (id) {
		case ESC_GRV:             key_if_mod(record, GRAVE_MODS,       KC_GRV,  KC_ESC); break;
		case H_DELC:              key_if_mod(record, MOD_BIT(KC_LCTL), KC_BSPC, KC_H); break;

		case RGBLED_TOGGLE:       if (record->event.pressed) { rgblight_toggle(); } break;
		case RGBLED_STEP_MODE:    if (record->event.pressed) { rgblight_step(); } break;
		case RGBLED_INCREASE_HUE: if (record->event.pressed) { rgblight_increase_hue(); } break;
		case RGBLED_DECREASE_HUE: if (record->event.pressed) { rgblight_decrease_hue(); } break;
		case RGBLED_INCREASE_SAT: if (record->event.pressed) { rgblight_increase_sat(); } break;
		case RGBLED_DECREASE_SAT: if (record->event.pressed) { rgblight_decrease_sat(); } break;
		case RGBLED_INCREASE_VAL: if (record->event.pressed) { rgblight_increase_val(); } break;
		case RGBLED_DECREASE_VAL: if (record->event.pressed) { rgblight_decrease_val(); } break;
	}
}
