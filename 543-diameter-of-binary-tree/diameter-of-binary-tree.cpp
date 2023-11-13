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

    int dfs(TreeNode* root, int &ans){
        if(root->left == NULL && root->right == NULL)
            return 0;
        int left_side = 0, right_side = 0;
        if(root->left != NULL)
            left_side = 1 + dfs(root->left, ans);
        if(root->right != NULL)
            right_side = 1 + dfs(root->right, ans);

        ans = max(ans, left_side + right_side);

        return max(left_side, right_side);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;

        int k = dfs(root, ans);

        return ans;
    }
};