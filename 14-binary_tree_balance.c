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
int height(const binary_tree_t *node)
{
	int left;
	int right;

	if (node == NULL)
	{
		return (0);
	}

	left = height(node->left);
	right = height(node->right);

	return (1 + (left > right ? left : right));
}

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height;
	int right_height;

	if (tree == NULL)
	{
		return (0);
	}

	left_height = height(tree->left);
	right_height = height(tree->right);

	return (left_height - right_height);
}
