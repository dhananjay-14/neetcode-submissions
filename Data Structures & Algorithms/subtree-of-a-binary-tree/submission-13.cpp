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
    void traverse(TreeNode* node,vector<int>& order){
        if(node==NULL){
            order.push_back(-1);
            return;
        } 
        order.push_back(node->val);
        traverse(node->left,order);
        traverse(node->right,order);
    }
    bool compare(vector<int>& o1, vector<int>& o2) {
    for (int i = 0; i + o2.size() <= o1.size(); i++) {
        int j = 0;
        while (j < o2.size() && o1[i + j] == o2[j]) {
            j++;
        }
        if (j == o2.size()) return true;
    }
    return false;
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<int>order1;
        vector<int>order2;
        traverse(root,order1);
        traverse(subRoot,order2);
        for(auto el:order1) cout<<"o1 "<<el<<endl;
        for(auto el:order2) cout<<"o2 "<<el<<endl;
        if(order1.size()<order2.size()) return false;
        return compare(order1,order2);
    }
};
