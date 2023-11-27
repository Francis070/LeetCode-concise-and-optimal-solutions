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
    
    int rec(TreeNode * root, bool rob, map<pair<TreeNode *, bool>, int> &dp){
        if(root == NULL){
            return 0;
        }

        if(dp.find({root, rob}) != dp.end()){
            return dp[{root, rob}];
        }

        int cur = 0;
        if(rob){

            cur = max(root->val + rec(root->left, 0, dp) + rec(root->right, 0, dp) , rec(root->left, 1, dp) + rec(root->right, 1, dp));

        }
        else{
            cur = rec(root->left, 1, dp) + rec(root->right, 1, dp);
        }

        return dp[{root, rob}] = cur;
    }

    int rob(TreeNode* root) {
        // vector<pair<TreeNode *, bool>> v (1e5, {NULL, })
        map<pair<TreeNode *, bool>, int> dp;
        int ans = max(rec(root, 1, dp), rec(root, 0, dp));

        return ans;
    }
};