//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* flattenhelper(TreeNode* root) {
        if (root == NULL)
            return NULL;
            
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = NULL;
        root->right = NULL;
        root->right = flattenhelper(left);
        
        TreeNode *cur = root;
        while(cur->right != NULL)
            cur = cur->right;
        cur->right = flattenhelper(right);
        return root;
    }
    void flatten(TreeNode* root) {
        flattenhelper(root); 
    }
};
