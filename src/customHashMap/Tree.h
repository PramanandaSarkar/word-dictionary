#ifndef TREE_H
#define TREE_H

// Binary Tree Node
typedef struct TreeNode {
    char *key;
    char *value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Tree function declarations
TreeNode *create_node(const char *key, const char *value);
TreeNode *insert_node(TreeNode *root, const char *key, const char *value);
const char *search_tree(TreeNode *root, const char *key);
void free_tree(TreeNode *root);

#endif
