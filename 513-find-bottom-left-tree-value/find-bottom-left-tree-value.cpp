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

    void rec(TreeNode * root, int level, pair<int, int> & ans){
        if(root == NULL)
            return;

        if(ans.first < level){
            ans = {level, root->val};
        }

        rec(root->left, level + 1, ans);
        rec(root->right, level + 1, ans);
    }
 
    int findBottomLeftValue(TreeNode* root) {
        pair<int, int> ans = {-1, -1};
        rec(root, 0, ans);

        return ans.second;
    }
};