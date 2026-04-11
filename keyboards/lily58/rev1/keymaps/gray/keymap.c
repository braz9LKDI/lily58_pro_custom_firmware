/*
    __  __     ______     __  __     __    __     ______     ______
    /\ \/ /    /\  ___\   /\ \_\ \   /\ "-./  \   /\  __ \   /\  == \
    \ \  _"-.  \ \  __\   \ \____ \  \ \ \-./\ \  \ \  __ \  \ \  _-/
    \ \_\ \_\  \ \_____\  \/\_____\  \ \_\ \ \_\  \ \_\ \_\  \ \_\
    \/_/\/_/   \/_____/   \/_____/   \/_/  \/_/   \/_/\/_/   \/_/
*/
#include QMK_KEYBOARD_H


enum layer_number {
	_BASE = 0,
	_LOWER,
	_RAISE,
	_GAMING,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* _BASE
	 * ,-------------------------------------.                ,-----------------------------------.
	 * |   `   |  1  |  2  |  3  |  4  |  5  |                |  6  |  7  |  8  |  9  |  0  |  \  |
	 * |-------+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
	 * |  TAB  |  Q  |  W  |  F  |  P  |  B  |                |  J  |  L  |  U  |  Y  |  ;  |  -  |
	 * |-------+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
	 * | LCTRL |  A  |  R  |  S  |  T  |  G  |-----.    ,-----|  M  |  N  |  E  |  I  |  O  |  '  |
	 * |-------+-----+-----+-----+-----+-----|  [  |    |  ]  |-----+-----+-----+-----+-----+-----|
	 * | LSHFT |  Z  |  X  |  C  |  D  |  V  |-----|    |-----|  K  |  H  |  ,  |  .  |  /  |RSHFT|
	 * `------------------------------------/     /     \      \----------------------------------'
	 *              | LOWER | LGUI |LALT | /SPACE/       \ENTER \  | Bksp | ESC | RAISE |
	 *              |       |      |     |/     /         \      \ |      |     |       |
	 *              `--------------------''----'           '-----''--------------------'
	 */
	[_BASE] = LAYOUT(
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
		KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                       KC_J,     KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS,
		KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                       KC_M,     KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,   KC_LBRC, KC_RBRC,   KC_K,     KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
		                    MO(_LOWER), KC_LGUI, KC_LALT,    KC_SPC,  KC_ENT,     KC_BSPC, KC_ESC,  MO(_RAISE)
	),

	/* _LOWER
	 * ,-----------------------------------------.                    ,-----------------------------------------.
	 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
	 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
	 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
	 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
	 * | CAPS | KP1  | KP2  | KP3  | KP4  | KP5  |-------.    ,-------| KP6  | KP7  | KP8  | KP9  | KP0  |      |
	 * |------+------+------+------+------+------| PLAY  |    |       |------+------+------+------+------+------|
	 * |LSHFT | MPRV | VOLD | VOLU | MNXT | MUTE |-------|    |-------|PRINT |DEL   |      |      |      |      |
	 * `-----------------------------------------/       /     \      \-----------------------------------------'
	 *                   |      |      |      | /       /       \      \  | Bksp | RALT |      |
	 *                   |      |      |      |/       /         \      \ |      |      |      |
	 *                   `--------------------''------'           '------''--------------------'
	 */
	[_LOWER] = LAYOUT(
		KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                       KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
		KC_CAPS, KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,                       KC_P6,    KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_NO,
		KC_LSFT, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE,   KC_MPLY, KC_NO,   KC_PSCR,  KC_DEL,  KC_NO,   KC_NO,   KC_NO,   KC_RSFT,
		                        _______, KC_NO, KC_NO,          KC_NO,   KC_NO,        KC_BSPC, KC_RALT, _______
	),

	/* RAISE
	 * ,-------------------------------------.                ,-----------------------------------------.
	 * |       |     |     |     |     |     |                |      |      |      |      |      |      |
	 * |-------+-----+-----+-----+-----+-----|                |------+------+------+------+------+------|
	 * |       |     |     |     |     |     |                |      |      | RGUI |      |      |      |
	 * |-------+-----+-----+-----+-----+-----|                |------+------+------+------+------+------|
	 * |       |     |     |     |     |     |-----.    ,-----|      | LEFT | DOWN |  UP  |RIGHT |      |
	 * |-------+-----+-----+-----+-----+-----|     |    |     |------+------+------+------+------+------|
	 * |       |     |     |     |     |     |-----|    |-----|      |  =   |NUMP- |NUMP+ |  |   |      |
	 * `-------------------------------------/     /    \      \----------------------------------------'
	 *                |GAMING|     |      | /     /      \      \ |      |      |      |
	 *                |      |     |      |/     /        \      \|      |      |      |
	 *                `-------------------''----'          '-----''--------------------'
	 */
	[_RAISE] = LAYOUT(
		KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                   KC_NO,    KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_NO,
		KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                   KC_NO,    KC_NO,   KC_RGUI,    KC_NO,      KC_NO,      KC_NO,
		KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                   KC_NO,    KC_LEFT, KC_DOWN,    KC_UP,      KC_RGHT,    KC_NO,
		KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO,   KC_NO,    KC_EQL,  KC_PMNS,    S(KC_EQL),  S(KC_BSLS), KC_NO,
		                TG(_GAMING),   KC_NO,   KC_LALT,     KC_SPC, KC_NO,     KC_NO,    KC_NO,  _______
	),

	/* _GAMING (QWERTY)
	 * ,-------------------------------------.                ,-----------------------------------.
	 * |  ESC  |  1  |  2  |  3  |  4  |  5  |                |  6  |  7  |  8  |  9  |  0  |  \  |
	 * |-------+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
	 * |  TAB  |  Q  |  W  |  E  |  R  |  T  |                |  Y  |  U  |  I  |  O  |  P  |  -  |
	 * |-------+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
	 * | LCTRL |  A  |  S  |  D  |  F  |  G  |-----.    ,-----|  H  |  J  |  K  |  L  |  ;  |  '  |
	 * |-------+-----+-----+-----+-----+-----|  [  |    |  ]  |-----+-----+-----+-----+-----+-----|
	 * | LSHFT |  Z  |  X  |  C  |  V  |  B  |-----|    |-----|  N  |  M  |  ,  |  .  |  /  |RSHFT|
	 * `------------------------------------/     /     \      \----------------------------------'
	 *              |   M   |  Y   |LALT | /SPACE/       \ENTER \ |      |     |GAMING |
	 *              |       |      |     |/     /         \      \|      |     |       |
	 *              `--------------------''----'           '-----''--------------------'
	 */
	[_GAMING] = LAYOUT(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
		KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_LBRC, KC_RBRC,  KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
		                     KC_M,   KC_Y,   KC_LALT,        KC_SPC,  KC_ENT,      KC_NO, KC_NO,  TG(_GAMING)
	)
};

// layer_state_t layer_state_set_user(layer_state_t state) {
// 	return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	if (!is_keyboard_master())
		return OLED_ROTATION_180; // flips the display 180 degrees if offhand
	return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
	if (is_keyboard_master()) {
		// If you want to change the display of OLED, you need to change here
		oled_write_ln(read_layer_state(), false);
		oled_write_ln(read_keylog(), false);
		oled_write_ln(read_keylogs(), false);
		//oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
		//oled_write_ln(read_host_led_state(), false);
		//oled_write_ln(read_timelog(), false);
	} else
		oled_write(read_logo(), false);

	return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record -> event.pressed) {
		#ifdef OLED_ENABLE
		set_keylog(keycode, record);
		#endif
		// set_timelog();
	}
	return true;
}
