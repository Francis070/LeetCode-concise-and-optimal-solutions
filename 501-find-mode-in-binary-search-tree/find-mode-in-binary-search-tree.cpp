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
    unordered_map<int, int> um;
    void rec(TreeNode * root){
        if(root == NULL)
            return;
        
        um[root->val]++;
        rec(root->left);
        rec(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        int mx = 0;
        rec(root);
        for(auto &x : um){
            mx = max(mx, x.second);
        }
        vector<int> ans;
        for(auto &x : um){
            if(x.second == mx)
                ans.push_back(x.first);
        }
        return ans;
    }
};