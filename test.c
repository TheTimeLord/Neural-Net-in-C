#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "dense.h"

int main(int argc, char *argv[]) {
	srand(time(0));

	struct Dense_Layer *layer = calloc(1, sizeof(struct Dense_Layer));

	dense_layer_init(layer, 4, 2, "test");

	print_layer(layer);

	dense_layer_free(layer);

	return 0;
}
