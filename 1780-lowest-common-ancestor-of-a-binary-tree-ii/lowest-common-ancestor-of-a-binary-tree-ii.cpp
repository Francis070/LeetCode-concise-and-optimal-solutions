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

    bool flca(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode * &ans){
        if(root == NULL)
            return false;

        bool lc = flca(root->left, p, q, ans);
        bool rc = flca(root->right, p, q, ans);

        if( (lc && rc) || ((root->val == p->val || root->val == q->val) && (lc || rc) ) ){
            ans = root;
        }

        if(root->val == p->val || root->val == q->val)
            return true;
        return lc || rc;
    }

    bool find(TreeNode * root, TreeNode * a){
        if(root == NULL)
            return false;

        if(root->val == a->val)
            return true;

        return find(root->left, a) || find(root->right, a);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(find(root, p) && find(root, q)){
        //     TreeNode * ans = NULL;
        //     bool x = flca(root, p, q, ans);
        //     return ans;
        // }
        // return NULL;
        TreeNode * ans = NULL;
        bool x = flca(root, p, q, ans);
        return ans;
    }
};