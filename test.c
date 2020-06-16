#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "dense.h"

int main(int argc, char *argv[]) {
	srand(time(0));

	int num_nodes = 1;

	struct Dense_Node *node[num_nodes];

	// initialize nodes
	for(int i=0; i < num_nodes; i++) {
		node[i] = dense_node_init(5);
	}

	// give random values to each of the weights for each of the nodes
	for(int k=0; k < num_nodes; k++) {
		for(int i=0; i < node[k]->num_weights; i++) {
			int num = rand() % 10;
			dense_node_set_weight(node[k], i, num);
		}
	}

	// print each node values
	for(int k=0; k < num_nodes; k++) {
		printf("NODE %d\n", k);
		print_node(node[k]);
	}


	// free all nodes
	for(int k=0; k < num_nodes; k++) {
		dense_node_free(node[k]);
	}

	return 0;
}
