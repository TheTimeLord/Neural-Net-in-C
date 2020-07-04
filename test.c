#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "dense.h"

int main(int argc, char *argv[]) {
	srand(time(0));

	struct Dense_Layer *first	= calloc(1, sizeof(struct Dense_Layer));
	struct Dense_Layer *second	= calloc(1, sizeof(struct Dense_Layer));
	struct Dense_Layer *output	= calloc(1, sizeof(struct Dense_Layer));

	dense_layer_init(first, 5, 3, "test");
	dense_layer_init(second, 5, 5, "test");
	dense_layer_init(output, 1, 5, "test");

	print_layer(first);
	printf("---------------------------------------\n");
	print_layer(second);
	printf("---------------------------------------\n");
	print_layer(output);


	printf("*****************\n");
	float in_test[5] = {1.1, -2.2, 3.3, -4.4, 5.5};
	sigmoid(in_test, second);

	dense_layer_free(first);
	dense_layer_free(second);
	dense_layer_free(output);

	return 0;
}
