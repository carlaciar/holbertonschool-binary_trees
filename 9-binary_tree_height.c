#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 *
 * Return: If tree is NULL, your function must return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left == NULL && tree->right == NULL)
	{
		return (0);
	}

	/* recursing down to find the height of each */
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	/**
	 * same as writing
	 * if (left_height > right_height)
	 * return (1 + left_height);
	 * else
	 * return (1 + right_height);
	 */
	return (1 + (left_height > right_height ? left_height : right_height));
}
