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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return vector<vector<int>>();
        queue<pair<TreeNode*,int>>q;
        vector<vector<int>>result;
        int curr = 1;
        q.push({root,1});
        vector<int>temp;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int lev = q.front().second;
            q.pop();
            if(lev==curr){
                temp.push_back(node->val);
            }else{
                result.push_back(temp);
                temp = vector<int>();
                curr++;
                temp.push_back(node->val);
            }

            if(node->left)q.push({node->left,lev+1});
            if(node->right)q.push({node->right,lev+1});
        }
        result.push_back(temp);
        return result;
    }
};
