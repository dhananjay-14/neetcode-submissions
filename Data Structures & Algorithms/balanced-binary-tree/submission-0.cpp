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
    bool result = true;
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        int leftHeight = 1 + dfs(root->left);
        int rightHeight = 1 + dfs(root->right);
        int diff = abs(leftHeight-rightHeight);
        result = result && (diff<=1);
        return max(leftHeight,rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return result;
    }
};
