/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <https://github.com/Legonut> wrote this file.  As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day, and
 * you think this stuff is worth it, you can buy me a beer in return. David Rauseo
 * ----------------------------------------------------------------------------
 */

#include "keycode.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H

enum sol_layers
{
	MAIN_LAYER,
	FN_LAYER,
	DOWNSHIFT_LAYER,
	NUMPAD_LAYER,
	NAVIGATION_LAYER,
	SOL_CONTROL_LAYER
};

enum sol_keycodes
{
	TCH_TOG = SAFE_RANGE,  // Disables touch processing
	MENU_BTN,
	MENU_UP,
	MENU_DN,
	RGB_RST,

	// Momentary Layer Switch
	FN_LAYER_KEY = MO(FN_LAYER),
	DOWNSHIFT_LAYER_KEY = MO(DOWNSHIFT_LAYER),
	NUMPAD_LAYER_KEY = MO(NUMPAD_LAYER),
	NAVIGATION_LAYER_KEY = MO(NAVIGATION_LAYER),

	// Toggle Layer
	SOL_CONTROL_LAYER_TOGGLE = TG(SOL_CONTROL_LAYER)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
	[MAIN_LAYER] = LAYOUT(
		KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,                  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
		KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,                  KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
		DOWNSHIFT_LAYER_KEY,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LPRN,                  KC_RPRN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
		KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LCBR,                  KC_RCBR, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
		KC_LCTL,  KC_LGUI, KC_LALT, RGB_TOG, KC_NO,  KC_SPC,  KC_PGDN, KC_DEL, KC_ENT,  KC_PGUP, KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RCTL,

		KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,                                     KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,
		KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                                       KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV
	),

	[FN_LAYER] = LAYOUT(
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
		_______, KC_HOME, KC_UP,   KC_END,  _______, _______, _______,                   _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PSCR, KC_PGUP,
		_______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,                   _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  KC_PGDN,
		_______,  AU_TOG,  MU_TOG,  MU_MOD, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
		_______, CK_TOGG,   CK_UP, CK_DOWN, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,

		_______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
	),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	switch (keycode)
	{
		case MENU_BTN:
			if (record->event.pressed)
			{ rgb_menu_selection(); }

			return false;

		case MENU_UP:
			if (record->event.pressed)
			{ rgb_menu_action(true); }

			return false;

		case MENU_DN:
			if (record->event.pressed)
			{ rgb_menu_action(false); }

			return false;

		case RGB_RST:
			if (record->event.pressed)
			{ eeconfig_update_rgb_matrix_default(); }

			return false;

		case TCH_TOG:
			if (record->event.pressed)
			{ touch_encoder_toggle(); }

			return false;  // Skip all further processing of this key

		default:
			return true;
	}
}
