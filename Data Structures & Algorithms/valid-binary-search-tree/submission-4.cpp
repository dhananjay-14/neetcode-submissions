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
    void traverse(TreeNode* root, vector<int>&arr){
        if(root==NULL) return ;
        traverse(root->left,arr);
        arr.push_back(root->val);
        traverse(root->right,arr);
    }
    bool isValidBST(TreeNode* root) {
       vector<int>inOrder;
       traverse(root,inOrder);
       for(int i= 0;i<inOrder.size()-1;i++){
         if(inOrder[i+1]<=inOrder[i]) return false;
       }
       return true;
    }
};
