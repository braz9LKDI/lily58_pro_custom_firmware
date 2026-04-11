# Lily58 Pro custom firmware

This repository is a fork of the [QMK userspace template](https://github.com/qmk/qmk_userspace) repository and contains my personal configuration of the [Lily58 Pro keyboard](https://github.com/kata0510/Lily58).

## Current config

This userspace currently builds one target:

- `lily58/rev1:gray`.

### Layer layout summary

- `_BASE`: Colemak-DH style base layer.

	```
	,-------------------------------------.                ,-----------------------------------.
	|   `   |  1  |  2  |  3  |  4  |  5  |                |  6  |  7  |  8  |  9  |  0  |  \  |
	|-------+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
	|  TAB  |  Q  |  W  |  F  |  P  |  B  |                |  J  |  L  |  U  |  Y  |  ;  |  -  |
	|-------+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
	| LCTRL |  A  |  R  |  S  |  T  |  G  |-----.    ,-----|  M  |  N  |  E  |  I  |  O  |  '  |
	|-------+-----+-----+-----+-----+-----|  [  |    |  ]  |-----+-----+-----+-----+-----+-----|
	| LSHFT |  Z  |  X  |  C  |  D  |  V  |-----|    |-----|  K  |  H  |  ,  |  .  |  /  |RSHFT|
	`------------------------------------/     /     \      \----------------------------------'
	             | LOWER | LGUI |LALT | /SPACE/       \ENTER \  | Bksp | ESC | RAISE |
	             |       |      |     |/     /         \      \ |      |     |       |
	             `--------------------''----'           '-----''--------------------'
	```

- `_LOWER`: function row, media controls and numpad keys.

	```
	,-----------------------------------------.                    ,-----------------------------------------.
	|      |      |      |      |      |      |                    |      |      |      |      |      |      |
	|------+------+------+------+------+------|                    |------+------+------+------+------+------|
	|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
	|------+------+------+------+------+------|                    |------+------+------+------+------+------|
	| CAPS | KP1  | KP2  | KP3  | KP4  | KP5  |-------.    ,-------| KP6  | KP7  | KP8  | KP9  | KP0  |      |
	|------+------+------+------+------+------| PLAY  |    |       |------+------+------+------+------+------|
	|LSHFT | MPRV | VOLD | VOLU | MNXT | MUTE |-------|    |-------|PRINT |DEL   |      |      |      |      |
	`-----------------------------------------/       /     \      \-----------------------------------------'
	                  |      |      |      | /       /       \      \  | Bksp | RALT |      |
	                  |      |      |      |/       /         \      \ |      |      |      |
	                  `--------------------''------'           '------''--------------------'
	```

- `_RAISE`: navigation and symbol helpers.

```
	,-------------------------------------.                ,-----------------------------------------.
	|       |     |     |     |     |     |                |      |      |      |      |      |      |
	|-------+-----+-----+-----+-----+-----|                |------+------+------+------+------+------|
	|       |     |     |     |     |     |                |      |      | RGUI |      |      |      |
	|-------+-----+-----+-----+-----+-----|                |------+------+------+------+------+------|
	|       |     |     |     |     |     |-----.    ,-----|      | LEFT | DOWN |  UP  |RIGHT |      |
	|-------+-----+-----+-----+-----+-----|     |    |     |------+------+------+------+------+------|
	|       |     |     |     |     |     |-----|    |-----|      |  =   |NUMP- |NUMP+ |  |   |      |
	`-------------------------------------/     /    \      \----------------------------------------'
	               |GAMING|     |      | /     /      \      \ |      |      |      |
	               |      |     |      |/     /        \      \|      |      |      |
	               `-------------------''----'          '-----''--------------------'
```

- `_GAMING`: QWERTY gaming layer.

	```
		,-------------------------------------.                ,-----------------------------------.
		|  ESC  |  1  |  2  |  3  |  4  |  5  |                |  6  |  7  |  8  |  9  |  0  |  \  |
		|-------+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
		|  TAB  |  Q  |  W  |  E  |  R  |  T  |                |  Y  |  U  |  I  |  O  |  P  |  -  |
		|-------+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
		| LCTRL |  A  |  S  |  D  |  F  |  G  |-----.    ,-----|  H  |  J  |  K  |  L  |  ;  |  '  |
		|-------+-----+-----+-----+-----+-----|  [  |    |  ]  |-----+-----+-----+-----+-----+-----|
		| LSHFT |  Z  |  X  |  C  |  V  |  B  |-----|    |-----|  N  |  M  |  ,  |  .  |  /  |RSHFT|
		`------------------------------------/     /     \      \----------------------------------'
		             |   M   |  Y   |LALT | /SPACE/       \ENTER \ |      |     |GAMING |
		             |       |      |     |/     /         \      \|      |     |       |
		             `--------------------''----'           '-----''--------------------'
	```

### Layer behavior

- `_LOWER` is activated with `MO(_LOWER)` from base.

- `_RAISE` is activated with `MO(_RAISE)` from base.

- `_GAMING` is toggled with `TG(_GAMING)`.

- Pressing LOWER and RAISE together is treated as a combo state for display only (no tri-layer callback in `keymap.c`).

### OLED behavior

- Master side shows layer state, keylog, and keylogs.

- Offhand side shows the logo.

- Layer text rendering uses a keymap-local source file at `keyboards/lily58/rev1/keymaps/gray/layer_state_reader.c`.

- `rules.mk` is configured to compile the local `layer_state_reader.c` file, so this repository's version is used by GitHub Actions.

### Build commands:

- Build all configured userspace targets: `qmk userspace-compile`.

- Build this keymap directly: `qmk compile -kb lily58 -km gray`.
