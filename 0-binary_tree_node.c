#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * binary_tree_node - creates a binary tree node
 * @parent: a pointer to the parent node of the node to create
 * @value: the value to put in the new node
 *
 * Return: a pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_binary_node = malloc(sizeof(binary_tree_t));

	if (new_binary_node == NULL)
		return (NULL);

	new_binary_node->n = value;
	new_binary_node->parent = parent;
	new_binary_node->left = NULL;
	new_binary_node->right = NULL;

	return (new_binary_node);
}
