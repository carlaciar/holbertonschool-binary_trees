#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * binary_tree_is_root - checks if a given node is a root
 * @node: a pointer to the node to check
 *
 * Return: 1 if node is a root, otherwise 0
 * If node is NULL, return 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	/* if node has a parent, it is not the root so return 0 */
	else if (node->parent != NULL)
		return (0);

	/* if node does not have a parent, is it a root so return 1 */
	else
		return (1);
}
