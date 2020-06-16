#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "dense.h"

int main(int argc, char *argv[]) {
	srand(time(0));

	struct Dense_Layer *layer = dense_layer_init(10, 3, "sigmoid");
	
	printf("init\n");

	print_layer(layer);

	dense_layer_free(layer);

	return 0;
}
