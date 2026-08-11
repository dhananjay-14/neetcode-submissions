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
    int node = 0;
    TreeNode* root = NULL;
    unordered_map<int,int>mp;

    void build(vector<int>& preorder, vector<int>& inorder,int start, int end,int dir,TreeNode* prevNode,unordered_map<int,int>&mp){
        if(start>end)return;
        TreeNode* nd = new TreeNode(preorder[node]);
        node++;
       
        if(prevNode){
            if(dir==0) prevNode->left = nd;
            if(dir==1) prevNode->right = nd;
        }else root = nd;

        int index = mp[nd->val];

        build(preorder,inorder,start,index-1,0,nd,mp);
        build(preorder,inorder,index+1,end,1,nd,mp);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i= 0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        build(preorder,inorder,0,inorder.size()-1,-1,NULL,mp);
        return root;
    }
};
