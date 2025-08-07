#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * binary_tree_delete - creates a binary tree node
 * @tree: a pointer to the root node of the tree to delete
 *
 * Return: the tree
 */
void binary_tree_delete(binary_tree_t *tree)
{
	/* if tree is null, do nothing */
	if (tree == NULL)
	{
		return;
	}

	/* delete right and left recursively, then free root */
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
