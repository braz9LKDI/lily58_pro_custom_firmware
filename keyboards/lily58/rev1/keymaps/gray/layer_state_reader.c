#include "action_layer.h"
#include <stdio.h>

#define L_BASE 0
#define L_LOWER (1 << 1) // 10 = 2
#define L_RAISE (1 << 2) // 100 = 4
#define L_LOWER_RAISE (L_LOWER | L_RAISE)
#define L_GAMING (1 << 3) // 1000 = 8

char layer_state_str[24];

const char *read_layer_state(void) {
	switch (layer_state) {
		case L_BASE:
			snprintf(layer_state_str, sizeof(layer_state_str), "Layer: base");
			break;
		case L_LOWER:
			snprintf(layer_state_str, sizeof(layer_state_str), "Layer: lower");
			break;
		case L_RAISE:
			snprintf(layer_state_str, sizeof(layer_state_str), "Layer: raise");
		break;
		case L_LOWER_RAISE:
			snprintf(layer_state_str, sizeof(layer_state_str), "Layer: lower + raise");
			break;
		case L_GAMING:
			snprintf(layer_state_str, sizeof(layer_state_str), "Layer: gaming");
			break;
		default:
			snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%u", (unsigned) get_highest_layer(layer_state));
	}

	return layer_state_str;
}
