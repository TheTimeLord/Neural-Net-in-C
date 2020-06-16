#ifndef H_DENSE
#define H_DENSE

struct Dense_Node {
	uint32_t num_weights;
	uint32_t *weight;
	uint32_t result;
};

struct Dense_Layer {
	char* activation;
	uint32_t num_nodes;
	struct Dense_Node *nodes;
};

/**************************************************
 *		Node Functions
 **************************************************/

struct Dense_Node *dense_node_init(uint32_t num_weights);

void dense_node_free(struct Dense_Node *node);

void dense_node_set_weight(struct Dense_Node *node, uint32_t input_loc, uint32_t weight);

void dense_node_set_result(struct Dense_Node *node, uint32_t result);

void print_node(struct Dense_Node *node);

/**************************************************
 *              Layer Functions
 **************************************************/

struct Dense_Layer *dense_layer_init(uint32_t num_nodes, char* activation);

#endif
