#include "binary_trees.h"
/**
 * binary_tree_balance - Calculates the balance factor of a binary tree.
 * @tree: A pointer to the root of the binary tree.
 *
 * Return: The balance factor of the binary tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = tree->left ? (int)binary_tree_height(tree->left) : -1;
	right_height = tree->right ? (int)binary_tree_height(tree->right) : -1;

	return (left_height - right_height);
}

