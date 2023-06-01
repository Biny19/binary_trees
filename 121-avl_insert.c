#include "binary_trees.h"
/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (tree == NULL)
        return NULL;

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return *tree;
    }
    if (value < (*tree)->n)
    {
        (*tree)->left = avl_insert(&((*tree)->left), value);
    }
    else if (value > (*tree)->n)
    {
        (*tree)->right = avl_insert(&((*tree)->right), value);
    }
    else
    {
        return NULL;  
    }

    (*tree)->height = 1 + _max(avl_height((*tree)->left), avl_height((*tree)->right));

    int balance = avl_balance_factor(*tree);
    if (balance > 1 && value < (*tree)->left->n)
    {
        return binary_tree_rotate_right(*tree);
    }
    if (balance < -1 && value > (*tree)->right->n)
    {
        return binary_tree_rotate_left(*tree);
    }
    if (balance > 1 && value > (*tree)->left->n)
    {
        (*tree)->left = binary_tree_rotate_left((*tree)->left);
        return binary_tree_rotate_right(*tree);
    }
    if (balance < -1 && value < (*tree)->right->n)
    {
        (*tree)->right = binary_tree_rotate_right((*tree)->right);
        return binary_tree_rotate_left(*tree);
    }

    return *tree;
}
/**
 * avl_height - Computes the height of an AVL tree
 * @tree: Pointer to the root node of the AVL tree
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
int avl_height(const avl_t *tree)
{
    if (tree == NULL)
        return 0;

    return tree->height;
}
/**
 * avl_balance_factor - Computes the balance factor of an AVL tree
 * @tree: Pointer to the root node of the AVL tree
 *
 * Return: Balance factor of the tree, or 0 if tree is NULL
 */
int avl_balance_factor(const avl_t *tree)
{
    if (tree == NULL)
        return 0;

    return avl_height(tree->left) - avl_height(tree->right);
}
/**
 * _max - Computes the maximum of two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: Maximum of a and b
 */
int _max(int a, int b)
{
    return (a > b) ? a : b;
}
