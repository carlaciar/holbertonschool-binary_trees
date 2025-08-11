#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: a pointer to the node to find the uncle
 *
 * Return: a pointer to the uncle node
 * If node is NULL, return NULL
 * If node has no uncle, return NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL ||
			node->parent->parent == NULL)
		return (NULL);

	if (node == node->parent->parent->left)
	{
		if (node->parent->parent->right != NULL)
			return (node->parent->parent->right);
		else
			return (NULL);
	}

	if (node == node->parent->parent->right)
	{
		if (node->parent->parent->left != NULL)
			return (node->parent->parent->left);
		else
			return (NULL);
	}

	return (NULL);
}
