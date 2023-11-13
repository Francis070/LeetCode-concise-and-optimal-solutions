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

    pair<int, int> dfs(TreeNode* root, int & ans){
        if(root->left == NULL && root->right == NULL)
            return {0, 0};
        
        pair<int, int> lft = {0, 0}, rgt = {0, 0};
        bool cl = false, cr = false;
        if(root->left != NULL){
            lft = dfs(root->left, ans);
            ans = max(ans, 1 + lft.second);
            cl = true;
        }
        if(root->right != NULL){
            rgt = dfs(root->right, ans);
            ans = max(ans, 1 + rgt.first);
            cr = true;
        }

        int gl = lft.second, gr = rgt.first;
        if(cl)  
            gl += 1;
        if(cr)
            gr += 1;
            
        return {gl, gr};
    }

    int longestZigZag(TreeNode* root) {
        int ans = 0;
        pair<int, int> def = dfs(root, ans);

        return ans;
    }
};