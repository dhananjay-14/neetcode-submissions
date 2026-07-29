/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxHeight = 0;
    int height(TreeNode* root){
        if(root==NULL) return 0;

        return 1 + max(height(root->left),height(root->right));
    }
    void dfs(TreeNode* root){
        if(root==NULL) return;
        maxHeight = max(maxHeight,height(root->left)+height(root->right));
        dfs(root->left);
        dfs(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxHeight;
    }
};
