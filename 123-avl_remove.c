#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: Pointer to the root node of the tree for removing a node.
 * @value: Value to remove in the tree.
 *
 * Return: Pointer to the new root node of the tree after removing
 *         the desired value.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node, *successor;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			node = root->left ? root->left : root->right;
			free(root);
			return (node);
		}
		else
		{
			successor = min_value_node(root->right);
			root->n = successor->n;
			root->right = avl_remove(root->right, successor->n);
		}
	}

	return (avl_balance(root));
}
