/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <https://github.com/Legonut> wrote this file.  As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day, and
 * you think this stuff is worth it, you can buy me a beer in return. David Rauseo
 * ----------------------------------------------------------------------------
 */

 /*
	Layer Template
	[TEMPLATE_LAYER_ID] =
		LAYOUT(
			KC_GESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BSPC,
			KC_TAB,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   MKI2C,                    MKI2C,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BSLS,
			DS_MOD,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   MKI2C,                    MKI2C,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_QUOT,
			KC_LSFT,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TOG_MOD,                  RGB_TOG, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SFTENT,
			KC_LCTL,  KC_LGUI, KC_LALT, KC_NO,   KC_NO,   KC_SPC,  NUM_MOD, NAV_MOD, FN_MOD, KC_NO,   KC_SPC,  KC_NO,   KC_RGUI, KC_DEL,  KC_RALT, KC_RCTL,

			KC_VOLD,  KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,                                    KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,
			KC_VOLD,  KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                                      KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV
		),
 */

#include "keycode.h"
#include "main_layer.h"
#include "quantum_keycodes.h"
#include "layers.h"
#include "rgb_matrix.h"
#include QMK_KEYBOARD_H

enum sol_layers
{
	MAIN_LAYER_ID,
	FN_LAYER_ID,
	DOWNSHIFT_LAYER_ID,
	NUMPAD_LAYER_ID,
	NAVIGATION_LAYER_ID,
	TOGGLE_CONTROL_LAYER_ID,
	SOL_CONTROL_LAYER_ID
};

enum occupied_keycodes
{
	MKI2C = 0x00 // Convenience/Friendly name for slots taken up by non-keys (such as the LED display)
};

enum sol_keycodes
{
	// Sol "Default" Keycodes -- Will keep these for reference, but currently are unused.
	TCH_TOG = SAFE_RANGE,  // Disables touch processing
	MENU_BTN,
	MENU_UP,
	MENU_DN,
	RGB_RST,

	// Momentary Layer Switch Keys
	FN_MOD = MO(FN_LAYER_ID),
	DS_MOD = MO(DOWNSHIFT_LAYER_ID),
	NUM_MOD = MO(NUMPAD_LAYER_ID),
	NAV_MOD = MO(NAVIGATION_LAYER_ID),
	TOG_MOD = MO(TOGGLE_CONTROL_LAYER_ID),
	// Sol Control Layer does not have a MOD entry as it should be very rare that we need to do anything with it,
	// and want to reduce the chance of accidentally interacting with it

	// Toggle Layer Keys
	FN_TOG = TG(FN_LAYER_ID),
	DS_TOG = TG(DOWNSHIFT_LAYER_ID),
	NUM_TOG = TG(NUMPAD_LAYER_ID),
	NAV_TOG = TG(NAVIGATION_LAYER_ID),
	// Toggle Layer does not have an entry, as it can't toggle itself (also that's probably not very useful anyway)
	SOL_TOG = TG(SOL_CONTROL_LAYER_ID)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
	                                                  //  Thm L,   Thm Up, Thm Dn, Thm Dn,  Thm Up,  Thm R

	// Main Layer
	[MAIN_LAYER_ID] =
		LAYOUT(
			KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,                  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
			KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    MKI2C,                    MKI2C,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
			DS_MOD,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    MKI2C,                    MKI2C,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
			KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    TOG_MOD,                  RGB_TOG, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
			KC_LCTL,  KC_LGUI, KC_LALT, KC_NO,   KC_NO,   KC_SPC,  NUM_MOD, NAV_MOD, FN_MOD, KC_NO,   KC_SPC,  KC_NO,   KC_RGUI, KC_DEL,  KC_RALT, KC_RCTL,

			KC_VOLD,  KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,                                    KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,
			KC_VOLD,  KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                                      KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV
		),

	// Function Keys
	[FN_LAYER_ID] =
		LAYOUT(
			KC_GESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                   KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
			KC_TAB,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   MKI2C,                    MKI2C,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BSLS,
			DS_MOD,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   MKI2C,                    MKI2C,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_QUOT,
			KC_LSFT,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   FN_TOG,                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SFTENT,
			KC_LCTL,  KC_LGUI, KC_LALT, KC_NO,   KC_NO,   KC_SPC,  NUM_MOD, NAV_MOD, FN_MOD, KC_NO,   KC_SPC,  KC_NO,   KC_RGUI, KC_DEL,  KC_RALT, KC_RCTL,

			KC_VOLD,  KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,                                    KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,
			KC_VOLD,  KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                                      KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV
		),

	// "Downshift" Layer (easy access to various symbols such as `-_+= etc.)
	[DOWNSHIFT_LAYER_ID] =
		LAYOUT(
			KC_GESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_DEL,
			KC_TAB,   KC_NO,   KC_NO,   KC_NO,   KC_MINS, KC_LCBR, MKI2C,                    MKI2C,   KC_RCBR, KC_PLUS, KC_NO,   KC_NO,   KC_NO,   KC_PIPE,
			DS_MOD,   KC_NO,   KC_NO,   KC_NO,   KC_UNDS, KC_LPRN, MKI2C,                    MKI2C,   KC_RPRN, KC_EQL,  KC_NO,   KC_NO,   KC_NO,   KC_GRV,
			KC_LSFT,  KC_NO,   KC_NO,   KC_NO,   KC_EXLM, KC_LBRC, DS_TOG,                   KC_NO,   KC_RBRC, KC_DLR,  KC_NO,   KC_NO,   KC_NO,   KC_SFTENT,
			KC_LCTL,  KC_LGUI, KC_LALT, KC_NO,   KC_NO,   KC_SPC,  NUM_MOD, NAV_MOD, FN_MOD, KC_NO,   KC_SPC,  KC_NO,   KC_RGUI, KC_DEL,  KC_RALT, KC_RCTL,

			KC_VOLD,  KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,                                    KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,
			KC_VOLD,  KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                                      KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV
		),

	// Numpad Layer
	[NUMPAD_LAYER_ID] =
		LAYOUT(
			KC_GESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                    KC_NO,   KC_NO,   KC_7,    KC_8,    KC_9,    KC_PLUS, KC_BSPC,
			KC_TAB,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   MKI2C,                    MKI2C,   KC_NO,   KC_4,    KC_5,    KC_6,    KC_MINS, KC_BSLS,
			DS_MOD,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   MKI2C,                    MKI2C,   KC_NO,   KC_1,    KC_2,    KC_3,    KC_SLSH, KC_QUOT,
			KC_LSFT,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   NUM_TOG,                    KC_NO,   KC_NO,   KC_0,    KC_0,    KC_DOT,  KC_ASTR, KC_SFTENT,
			KC_LCTL,  KC_LGUI, KC_LALT, KC_NO,   KC_NO,   KC_SPC,  NUM_MOD, NAV_MOD, FN_MOD, KC_NO,   KC_SPC,  KC_NO,   KC_RGUI, KC_DEL,  KC_RALT, KC_RCTL,

			KC_VOLD,  KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,                                    KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,
			KC_VOLD,  KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                                      KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV
		),

	// Navigation Layer (Arrow Keys, Home, End, Etc.)
	[NAVIGATION_LAYER_ID] =
		LAYOUT(
			KC_GESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BSPC,
			KC_TAB,   KC_INS,  KC_HOME, KC_PGUP, KC_NO,   KC_NO,   MKI2C,                    MKI2C,   KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,   KC_BSLS,
			DS_MOD,   KC_DEL,  KC_END,  KC_PGDN, KC_NO,   KC_NO,   MKI2C,                    MKI2C,   KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_QUOT,
			KC_LSFT,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   NAV_TOG,                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SFTENT,
			KC_LCTL,  KC_LGUI, KC_LALT, KC_NO,   KC_NO,   KC_SPC,  NUM_MOD, NAV_MOD, FN_MOD, KC_NO,   KC_SPC,  KC_NO,   KC_RGUI, KC_DEL,  KC_RALT, KC_RCTL,

			KC_VOLD,  KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,                                    KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,
			KC_VOLD,  KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                                      KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV
		),

	// "Toggling" controls. Ie: toggle layers on and off instead of temporarily enabling (mod)
	[TOGGLE_CONTROL_LAYER_ID] =
		LAYOUT(
			KC_GESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BSPC,
			KC_TAB,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   MKI2C,                    MKI2C,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BSLS,
			DS_MOD,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   MKI2C,                    MKI2C,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_QUOT,
			KC_LSFT,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TOG_MOD,                  SOL_TOG, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SFTENT,
			KC_LCTL,  KC_LGUI, KC_LALT, KC_NO,   KC_NO,   KC_SPC,  NUM_TOG, NAV_TOG, FN_TOG, KC_NO,   KC_SPC,  KC_NO,   KC_RGUI, KC_DEL,  KC_RALT, KC_RCTL,

			KC_VOLD,  KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,                                    KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,
			KC_VOLD,  KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                                      KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV
		),

	// Sol Control Layer (RGB Settings, reset EEPROM, reboot, etc.)
	[SOL_CONTROL_LAYER_ID] =
		LAYOUT(
			KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT,                  EE_CLR,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
			KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   MKI2C,                    MKI2C,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
			KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   MKI2C,                    MKI2C,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
			KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   SOL_TOG,                  QK_RBT,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
			KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

			KC_VOLD,  KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,                                    KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU,
			KC_VOLD,  KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                                      KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV
		),
};

// 
void process_numpad(void);
void process_numpad() {
	return;
}



bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	switch (keycode)
	{
		//  == Sol3 "Default" functionality == //
		// Need to read on what exactly they do before possibly removing them
		case MENU_BTN:
			if (record->event.pressed)
			{ rgb_menu_selection(); }

			return false;  // Skip all further processing of this key

		case MENU_UP:
			if (record->event.pressed)
			{ rgb_menu_action(true); }

			return false;  // Skip all further processing of this key

		case MENU_DN:
			if (record->event.pressed)
			{ rgb_menu_action(false); }

			return false;  // Skip all further processing of this key

		case RGB_RST:
			if (record->event.pressed)
			{ eeconfig_update_rgb_matrix_default(); }

			return false;  // Skip all further processing of this key

		case TCH_TOG:
			if (record->event.pressed)
			{ touch_encoder_toggle(); }

			return false;  // Skip all further processing of this key


		// == Custom key/event handling == //

		// Function Layer event handlers
		case FN_MOD:
			if(record->event.pressed)
			{}

			return true;

		case FN_TOG:
			if(record->event.pressed)
			{}

			return true;

		// Downshift Layer event handlers
		case DS_MOD:
			if(record->event.pressed)
			{}

			return true;

		case DS_TOG:
			if (record->event.pressed)
			{}

			return true;

		// Numpad Layer event handlers
		case NUM_MOD:
			if(record->event.pressed)
			{}

			return true;

		case NUM_TOG:
			if (record->event.pressed)
			{}

			return true;

		// Navigation Layer event handlers
		case NAV_MOD:
			if(record->event.pressed)
			{}

			return true;

		case NAV_TOG:
			if (record->event.pressed)
			{}

			return true;

		// Toggle Control Layer event handlers
		case TOG_MOD:
			if(record->event.pressed)
			{}

			return true;

		// Sol Control Layer event handlers
		case SOL_TOG:
			if(record->event.pressed)
			{}

			return true;


		// == No relevant cases == //
		default:
			return true;
	}
}
