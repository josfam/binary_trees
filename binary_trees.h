#ifndef BINARY_TREES_HEADER
#define BINARY_TREES_HEADER

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* Prints a binary tree just like the examples */
void binary_tree_print(const binary_tree_t *);

/* Creates a binary tree node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* Inserts a node as the left-child of another node */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* Inserts a node as the right-child of another node */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/* Checks if a node is a leaf */
int binary_tree_is_leaf(const binary_tree_t *node);

/* Checks if a given node is a root */
int binary_tree_is_root(const binary_tree_t *node);

#endif
