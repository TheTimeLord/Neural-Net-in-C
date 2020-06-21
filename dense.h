#ifndef H_DENSE
#define H_DENSE

struct Dense_Layer {
	char *activation;
	uint32_t num_nodes;
	uint32_t num_input;
	uint32_t **weights;
};

/**************************************************
 *              Layer Functions
 **************************************************/

void dense_layer_init(struct Dense_Layer *layer, uint32_t num_nodes, uint32_t num_input, char activation[10]);

void dense_layer_free(struct Dense_Layer *layer);

void dense_layer_set_weights(struct Dense_Layer *layer, uint32_t node, uint32_t *weights);

void print_layer(struct Dense_Layer *layer);


#endif
