#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

/*******************************************************
 * STRUCTS
 *******************************************************/

struct Dense_Node {
	uint32_t num_weights;
	uint32_t *weight;
	uint32_t result;
};


/*******************************************************
 * NODE FUNCTIONS
 *******************************************************/


/*
 * dense_node_init()
 * initializes a node
 */
struct Dense_Node *dense_node_init(uint32_t num_weights) {
	struct Dense_Node *node = calloc(1, sizeof(*node));
	if(!node) {
		perror("calloc failed");
		exit(1);
	}

	node->num_weights	= num_weights;
	node->result		= 0;
	node->weight		= calloc(num_weights, sizeof(uint32_t));
	
	return node;
}

/*
 * dense_node_free()
 * frees a node
 */
void dense_node_free(struct Dense_Node *node) {
	free(node->weight);
	free(node);
	return;
}

/*
 * dense_node_set_weight()
 * sets a particular weight for a node
 */
void dense_node_set_weight(struct Dense_Node *node, uint32_t input_loc, uint32_t weight) {
	if(input_loc >= node->num_weights) {
		printf("weight %d OUT OF BOUNDS for input_loc %d. MAX LOCATION = %d", weight, input_loc, node->num_weights - 1);
		exit(1);
	}
	node->weight[input_loc] = weight;
}


/*
 * dense_node_set_result()
 * set the result of a node
 */
void dense_node_set_result(struct Dense_Node *node, uint32_t result) {
	node->result = result;
}

/*
 * print_node()
 * prints the values of a given node
 */
void print_node(struct Dense_Node *node) {
	printf("result: %d\n", node->result);
	printf("num_weights: %d\n", node->num_weights);
	for(int i=0; i < node->num_weights; i++) {
		printf("weight[%d]: %d\n", i, node->weight[i]);
	}
}

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
