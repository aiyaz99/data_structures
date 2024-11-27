/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    // Base case: if root is NULL or the value is found
    if (root == NULL || root->val == val) {
        return root;
    }
    
    // If the value to search is smaller than the root's value,
    // continue searching in the left subtree.
    if (val < root->val) {
        return searchBST(root->left, val);
    }
    
    // Otherwise, search in the right subtree.
    return searchBST(root->right, val);
}

// Helper function to create a new TreeNode.
struct TreeNode* newNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}