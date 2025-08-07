#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: a pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 *
 * Return: a pointer to the created node,
 * or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_left_node = malloc(sizeof(binary_tree_t));

	if (parent == NULL)
		free(new_left_node);
		return (NULL);

	if (new_left_node == NULL)
		return (NULL);

	/* if parent is null, insert new node as is */
	else if (parent->left == NULL)
	{
		parent->left = new_left_node;
		new_left_node->n = value;
		new_left_node->parent = parent;
		new_left_node->left = NULL;
		new_left_node->right = NULL;
	}

	else if (parent->left != NULL)
	{
		/* moving parent->left to temp location */
		binary_tree_t *temp_left = parent->left;

		/* insert new left node */
		parent->left = new_left_node;
		new_left_node->n = value;
		new_left_node->parent = parent;
		new_left_node->left = temp_left;
		new_left_node->right = NULL;

		/* change temp left to go under new left node */
		temp_left->parent = new_left_node;
	}

	return (new_left_node);
}
