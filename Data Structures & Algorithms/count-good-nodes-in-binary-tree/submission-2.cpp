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
    int count = 0;
    void isGoodNode(TreeNode* root,int currMax){
        if(root==NULL) return;

        if(root->val >= currMax) count++;
        if(root->val > currMax) currMax = root->val;
        isGoodNode(root->left,currMax);
        isGoodNode(root->right,currMax);
    }
    int goodNodes(TreeNode* root) {
       int currMax = INT_MIN;
       isGoodNode(root,currMax);
       return count;
    }
};
