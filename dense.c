#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "dense.h"


/*******************************************************
 *		LAYER FUNCTIONS
 *******************************************************/


/*
 * dense_layer_init()
 *
 * input: (Dense_Layer) layer, (uint32) num_nodes, (uint32) num_input, (string) activation
 *
 * output: Initializes a Dense_Layer with num_nodes amount of nodes, all initialized with each node
 * 	   having weights equal to the number of nodes in the input. Activation function will be set too.
 *	   Weights for each node will have random initializations between -100 and 100.
 */

void dense_layer_init(struct Dense_Layer *layer, uint32_t num_nodes, uint32_t num_input, char activation[10]) {

	layer->activation	= activation;
	layer->num_nodes	= num_nodes;
	layer->num_input	= num_input;

	// Allocate an array of uint32 pointers; each pointer will be an array of weights for each node.

	layer->weights = calloc(num_nodes, sizeof(float *));
	if(!layer->weights) {
		perror("weights calloc failed");
		exit(1);
	}
	
	// Allocate an array of uint32. These will be the weights for each node.
	for(int i=0; i < num_nodes; i++) {
		layer->weights[i] = calloc(num_input, sizeof(float));
		if(!layer->weights[i]) {
                	perror("node calloc failed");
                	exit(1);
		}

		// set the initial weights to a value between -100 and 100
		for(int k=0; k < num_input; k++) {
			int pos		= (rand() % 2);
			float num	= (float) rand() / RAND_MAX;
			num = num * 100;
			if(!pos) {
				num = num * -1;
			}
			layer->weights[i][k] = num;
		}

	}

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
		free(layer->weights[i]);
	}
	free(layer->weights);
}

/*
 * dense_layer_set_weights()
 *
 * input: (Dense_Layer) layer, (uint32) node, (float *) weights
 *
 * output: Sets the weight of a connection from a node to the previous.
 */

void dense_layer_set_weights(struct Dense_Layer *layer, uint32_t node, uint32_t connection, float weight) {
	layer->weights[node][connection] = weight;
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
		for(int k=0; k < layer->num_input; k++) {
			printf("weight[%d]: %f\n", k, layer->weights[i][k]);
		}
	}
	printf("activation: %s\n", layer->activation);
	printf("num_nodes: %d\n", layer->num_nodes);
	printf("inputs per node: %d\n", layer->num_input);
}


/*******************************************************
 *              ACTIVATION FUNCTIONS
 *******************************************************/

void sigmoid(float *input, struct Dense_Layer *layer) {
	// Go through each node in the layer
	for(int i=0; i < layer->num_nodes; i++) {
		float sum = 0.0;
		for(int k=0; k < layer->num_input; k++) {
			sum += layer->weights[i][k] * input[k];
		}

		//TODO: Add a bias term to be used in the weighted sum.

		printf("weighted sum = %f\n", sum);
	}
}
