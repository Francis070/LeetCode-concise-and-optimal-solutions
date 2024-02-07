/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool find_lca(TreeNode * root, TreeNode * p, TreeNode * q, TreeNode * &ans){
        if(root == NULL){
            return false;
        }

        

        bool l_chk = false, r_chk = false;
        l_chk = find_lca(root->left, p, q, ans);
        r_chk = find_lca(root->right, p, q, ans);
        if((l_chk && r_chk) || ((root->val == p->val || root->val == q->val) && (l_chk || r_chk))){
            ans = root;
            // return true;
        }

        if(root->val == p->val || root->val == q->val)
            return true;

        return l_chk || r_chk;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * ans = NULL;
        bool chk = find_lca(root, p, q, ans);

        return ans;
    }
};