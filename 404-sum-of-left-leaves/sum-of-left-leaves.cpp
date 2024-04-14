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

    int func(TreeNode * root, bool check){
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL && check == 0){
            return root->val;
        }
        else if(root->left == NULL && root->right == NULL)
            return 0;
        
        int sum = 0;
        sum += func(root->left, 0);
        sum += func(root->right, 1);

        return sum;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int ans = func(root, 1);

        return ans;
    }
};