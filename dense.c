#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "dense.h"

/*******************************************************
 *		NODE FUNCTIONS
 *******************************************************/


/*
 * dense_node_init()
 * 
 * input: (uint32) num_weights
 *
 * output: Returns a memory allocated node with num_weights amount of weights
 */
struct Dense_Node *dense_node_init(uint32_t num_weights) {
	struct Dense_Node *node = calloc(1, sizeof(struct Dense_Node));
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
 * 
 * input: (Dense_Node) node
 *
 * output: Void. Frees the memory associated with node.
 */
void dense_node_free(struct Dense_Node *node) {
	free(node->weight);
	free(node);
	return;
}

/*
 * dense_node_set_weight()
 * 
 * input: (Dense_Node) node, (uint32) input_loc, (uint32) weight
 *
 * output: Void. Sets the node's weight value for a specific connection to previous layer.
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
 * 
 * input: (Dense_Node) node, (uint32) result
 *
 * output: Void. Sets the result of node. Result will be calculated by passing weighted average to activation function.
 */
void dense_node_set_result(struct Dense_Node *node, uint32_t result) {
	node->result = result;
}

/*
 * print_node()
 * 
 * input: (Dense_Node) node
 *
 * output: Void. Prints all data associated with node.
 */
void print_node(struct Dense_Node *node) {
	printf("result: %d\n", node->result);
	printf("num_weights: %d\n", node->num_weights);
	for(int i=0; i < node->num_weights; i++) {
		printf("weight[%d]: %d\n", i, node->weight[i]);
	}
}

/*******************************************************
 *		LAYER FUNCTIONS
 *******************************************************/

/*
 * dense_layer_init()
 *
 * input: (uint32) num_nodes, (string) activation
 *
 * output: Returns a Dense_Layer with num_nodes amount of nodes, all initialized. Activation function will be set too.
 *
 */

struct Dense_Layer *dense_layer_init(uint32_t num_nodes, char* activation) {
	struct Dense_Layer *layer = calloc(1, sizeof(struct Dense_Layer));


	return layer;
}
