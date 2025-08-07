#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * binary_tree_depth - measures the depth of a binary tree
 * @tree: a pointer to the root node of the tree to measure the depth
 *
 * Return: If tree is NULL, your function must return 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t left_depth;
	size_t right_depth;

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left == NULL && tree->right == NULL)
	{
		return (0);
	}

	/* recursing down to find the depth of each */
	left_depth = binary_tree_height(tree->left);
	right_depth = binary_tree_height(tree->right);

	return (1 + (left_depth > right_depth ? left_depth : right_depth));
}
