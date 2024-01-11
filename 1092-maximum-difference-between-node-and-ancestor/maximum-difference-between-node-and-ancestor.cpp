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

    void dfs(TreeNode * root, int cmax, int cmin, int &ans){
        if(root == NULL)
            return;
        
        cmax = max(root->val, cmax);
        cmin = min(root->val, cmin);

        ans = max(ans, cmax - cmin);
        dfs(root->left, cmax, cmin, ans);
        dfs(root->right, cmax, cmin, ans);
    }

    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        dfs(root, INT_MIN, INT_MAX, ans);

        return ans;
    }
};