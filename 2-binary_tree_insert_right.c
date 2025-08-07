#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: a pointer to the node to insert the right-child in
 * @value: the value to store in the new node
 *
 * Return: a pointer to the created node,
 * or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_right_node = malloc(sizeof(binary_tree_t));

	if (parent == NULL)
	{
		free(new_right_node);
		return (NULL);
	}

	if (new_right_node == NULL)
		return (NULL);

	/* if parent is null, insert new node as is */
	else if (parent->right == NULL)
	{
		parent->right = new_right_node;
		new_right_node->n = value;
		new_right_node->parent = parent;
		new_right_node->left = NULL;
		new_right_node->right = NULL;
	}

	else if (parent->right != NULL)
	{
		/* moving parent->right to temp location */
		binary_tree_t *temp_right = parent->right;

		/* insert new right node */
		parent->right = new_right_node;
		new_right_node->n = value;
		new_right_node->parent = parent;
		new_right_node->right = temp_right;
		new_right_node->left = NULL;

		/* change temp right to go under new right node */
		temp_right->parent = new_right_node;
	}

	return (new_right_node);
}
