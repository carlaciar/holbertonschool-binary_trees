#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 *
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->parent == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
	{
		return (0);
	}

	left_height = binary_tree_balance(tree->left);
	right_height = binary_tree_balance(tree->right);

	return (1 + (left_height - right_height));
}
