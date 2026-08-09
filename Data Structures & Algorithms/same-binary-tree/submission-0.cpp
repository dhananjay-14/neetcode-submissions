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
    bool same = true;

    void traverse(TreeNode* p, TreeNode*q){
        if(p==NULL && q == NULL)return;
        if((p==NULL && q!=NULL)||(p!=NULL && q==NULL))same = false;

        if(p!=NULL && q!=NULL){
           int v1 = p->val;
           int v2 = q->val;
           if(v1!=v2) same = false;
           traverse(p->left,q->left);
           traverse(p->right,q->right);
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        traverse(p,q);
        return same;
    }
};
