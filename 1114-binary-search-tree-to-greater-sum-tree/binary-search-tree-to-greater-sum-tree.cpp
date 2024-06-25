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

    int rec(TreeNode * root, int rs){
        if(root == NULL)
            return 0;

        int rt = rec(root->right, rs);
        if(root->right == NULL){
            rt += rs;
        }
        root->val += rt;
        rs = root->val;
        int lt = rec(root->left, rs);

        return max(rs, lt);
    }

    TreeNode* bstToGst(TreeNode* root) {
        int re = 0;
        int totsum = rec(root, re);

        return root;
    }
};