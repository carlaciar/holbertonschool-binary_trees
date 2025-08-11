#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: a pointer to the node to find the sibling
 *
 * Return: a pointer to the sibling node
 * If node is NULL or the parent is NULL, return NULL
 * If node has no sibling, return NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node == node->parent->left)
	{
		if (node->parent->right != NULL)
			return (node->parent->right);

		else
			return (NULL);
	}

	if (node == node->parent->right)
	{
		if (node->parent->left != NULL)
			return (node->parent->left);

		else
			return (NULL);
	}

	return (NULL);
}
