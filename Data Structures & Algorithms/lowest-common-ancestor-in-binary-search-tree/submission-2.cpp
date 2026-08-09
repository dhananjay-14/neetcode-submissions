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
    unordered_map<TreeNode*,bool>path;
    TreeNode* commonNode = NULL;
    void findNode(TreeNode* src,TreeNode* root,TreeNode* node,int itr){
        if(node==NULL || root==NULL) return;
       
        int curr = root->val;
        int tar = node->val;
        if(itr==1)path[root] = true;
        else{
           if (path[root])commonNode = root;
           else return;
        }
        if(node==root)return;
        if(curr<tar) findNode(root,root->right,node,itr);
        else findNode(root,root->left,node,itr);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findNode(NULL,root,p,1);
        findNode(NULL,root,q,2);
        return commonNode;
    }
};
