#include "Tree.h"
#include "../utils/helper.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Create a new tree node
TreeNode *create_node(const char *key, const char *value) {
    TreeNode *node = malloc(sizeof(TreeNode));
    if (!node) {
        perror("Failed to allocate memory for tree node");
        exit(EXIT_FAILURE);
    }

    node->key = custom_strdup(key); // Use custom_strdup instead of strdup
    node->value = custom_strdup(value); // Use custom_strdup instead of strdup
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert into the tree
TreeNode *insert_node(TreeNode *root, const char *key, const char *value) {
    if (!root) {
        return create_node(key, value);
    }

    if (strcmp(key, root->key) < 0) {
        root->left = insert_node(root->left, key, value);
    } else if (strcmp(key, root->key) > 0) {
        root->right = insert_node(root->right, key, value);
    } else {
        free(root->value);
        root->value = custom_strdup(value); // Update the value for an existing key
    }

    return root;
}

// Search for a key in the tree
const char *search_tree(TreeNode *root, const char *key) {
    if (!root) {
        return NULL;
    }

    int cmp = strcmp(key, root->key);
    if (cmp < 0) {
        return search_tree(root->left, key);
    } else if (cmp > 0) {
        return search_tree(root->right, key);
    } else {
        return root->value;
    }
}

// Free the tree
void free_tree(TreeNode *root) {
    if (!root) {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    free(root->key);
    free(root->value);
    free(root);
}
