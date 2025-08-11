#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * tree_depth - finding the depth
 * @tree: a pointer to the node
 *
 * Return: the depth of the node
 */
size_t tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* if tree is the root, return 0 */
	if (tree->parent == NULL)
	{
		return (0);
	}

	return (1 + tree_depth(tree->parent));
}

/**
 * is_perfect_helper - Recursively checks if the subtree is perfect.
 * @node: Pointer to the current node.
 * @expected_depth: The depth all leaves should have.
 *
 * Return: 1 if the subtree is perfect, 0 otherwise.
 */
int is_perfect_helper(const binary_tree_t *node, size_t expected_depth)
{
	/* check if an empty tree is perfect */
	if (node == NULL)
		return (1);

	/* check if node is a leaf */
	if (node->left == NULL && node->right == NULL)
	{
		/* leaf's depth must match expected depth */
		if (tree_depth(node) == expected_depth)
			return (1);
		else
			return (0);
	}

	/* if node has only one child, it's not full, so not perfect */
	if (node->left == NULL || node->right == NULL)
		return (0);

	/* recurse on left and right subtrees */
	return (is_perfect_helper(node->left, expected_depth) &&
			is_perfect_helper(node->right, expected_depth));
}


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	const binary_tree_t *node = tree;
	size_t expected_depth;

	if (tree == NULL)
		return (0);

	/* find the leftmost leaf to get the expected leaf depth */
	while (node->left != NULL)
		node = node->left;

	expected_depth = tree_depth(node);

	/* use helper to check if the whole tree is perfect */
	return (is_perfect_helper(tree, expected_depth));
}
