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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return vector<int>();
        vector<int>result;
        queue<pair<TreeNode*,int>>bfs;
        bfs.push({root,1});

        while(!bfs.empty()){
            TreeNode* curr = bfs.front().first;
            int lev = bfs.front().second;
            bfs.pop();

            if(curr->left) bfs.push({curr->left,lev+1});
            if(curr->right) bfs.push({curr->right,lev+1});  

            if(bfs.empty()){
                result.push_back(curr->val);
                return result;
            }

            int nextLev = bfs.front().second;
            if(nextLev>lev) result.push_back(curr->val);
        }
        return result;
    }
};
