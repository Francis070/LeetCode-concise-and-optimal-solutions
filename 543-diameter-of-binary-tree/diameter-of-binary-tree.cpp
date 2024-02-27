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

    int lng(TreeNode * root){
        if(root == NULL)
            return 0;
        
        int cmax = 0;
        int lft = 0, rht = 0;
        if(root->left != NULL)
            lft = 1 + lng(root->left);
        if(root->right != NULL)
            rht = 1 + lng(root->right);

        cmax = max(lft, rht);
        return cmax;
    }

    int rec(TreeNode * root, int & ans){
        if(root == NULL)
            return 0;
        
        int lft = 0, rht = 0;
        if(root->left != NULL)
            lft = 1 + rec(root->left, ans);
        if(root->right != NULL)
            rht = 1 + rec(root->right, ans);
        // cout<<root->val<<" "<<lft<<" "<<rht<<endl;
        // rec(root->left, ans);
        // rec(root->right, ans);
        ans = max(ans, lft + rht);
        return max(lft, rht);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        rec(root, ans);
        return ans;
    }
};