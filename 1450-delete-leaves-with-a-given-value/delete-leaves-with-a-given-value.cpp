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

    bool del(TreeNode * root, int tar){
        if(root == NULL)
            return true;

        bool lft = del(root->left, tar);
        bool rig = del(root->right, tar);

        if(lft)
            root->left = NULL;
        if(rig)
            root->right = NULL;

        if(root->left == NULL && root->right == NULL && root->val == tar){
            return true;
        }

        return false;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool re = del(root, target);

        if(re)
            return NULL;
        return root;
        // return NULL;
    }
};