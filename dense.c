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

	printf("Node created\n");

	node->num_weights	= num_weights;
	node->result		= 0;
	node->weight		= calloc(num_weights, sizeof(uint32_t));
	
	printf("Weights allocated\n");

	return node;
}

/*
 * dense_node_free()
 * 
 * input: (Dense_Node) node
 *
 * output: Frees the memory associated with node.
 */
void dense_node_free(struct Dense_Node *node) {
	free(node->weight);
	free(node);
}

/*
 * dense_node_set_weight()
 * 
 * input: (Dense_Node) node, (uint32) input_loc, (uint32) weight
 *
 * output: Sets the node's weight value for a specific connection to previous layer.
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
 * output: Sets the result of node. Result will be calculated by passing weighted average to activation function.
 */
void dense_node_set_result(struct Dense_Node *node, uint32_t result) {
	node->result = result;
}

/*
 * print_node()
 * 
 * input: (Dense_Node) node
 *
 * output: Prints all data associated with node.
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
 * input: (uint32) num_nodes, (uint32) input, (string) activation
 *
 * output: Returns a Dense_Layer with num_nodes amount of nodes, all initialized with each node
 * 	   having weights equal to the number of nodes in the input. Activation function will be set too.
 *	   Weights for each node will have random initializations up to 999.
 */

struct Dense_Layer *dense_layer_init(uint32_t num_nodes, uint32_t input, char activation[10]) {
	struct Dense_Layer *layer = calloc(1, sizeof(struct Dense_Layer));
	if(!layer) {
		perror("calloc failed");
		exit(1);
	}

	printf("got a layer\n");

	layer->activation	= activation;
	layer->num_nodes	= num_nodes;

	printf("got activation and num nodes\n");

	for(int i=0; i < num_nodes; i++) {

		printf("starting making node[%d]\n", i);

		layer->node[i] = dense_node_init(input);

		printf("node[%d] initialized\n", i);


		for(int k=0; k < input; k++) {
			uint32_t num = rand() % 1000;

			printf("random weight aquired\n");

			dense_node_set_weight(layer->node[i], k, num);

			printf("weight set\n");
		}
	}

	return layer;
}

/*
 * dense_layer_free()
 *
 * input: (Dense_Layer) layer
 *
 * output: Void. Frees all memory associated with a given layer.
 */

void dense_layer_free(struct Dense_Layer *layer) {
	for(int i=0; i < layer->num_nodes; i++) {
		dense_node_free(layer->node[i]);
	}
	free(layer);
}

/*
 * print_layer()
 *
 * intput: (Dense_Layer) layer
 *
 * output: Prints all the data associated with each node in layer as well as other Layer data.
 *
 */

void print_layer(struct Dense_Layer *layer) {
	for(int i=0; i < layer->num_nodes; i++) {
		printf("NODE[%d]\n", i);
		print_node(layer->node[i]);
	}
	printf("activation: %s\n", layer->activation);
}
