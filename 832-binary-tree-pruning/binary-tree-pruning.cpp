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

    int prune(TreeNode * t){
        if(t == NULL)
            return 0;
        
        int l = prune(t->left);
        int r = prune(t->right);

        if(l == 0)
            t->left = NULL;
        if(r == 0)
            t->right = NULL;
        if(l == 0 && r == 0 && t->val == 0)
            t = NULL;
        
        if(t != NULL)
            return (l + r + t->val);
        else
            return 0;
    }

    TreeNode* pruneTree(TreeNode* root) {
        int v = prune(root);
        if(root->val == 0 && v == 0)
            return NULL;
        return root;
    }
};