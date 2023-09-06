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

    vector<int> v;

    void store(TreeNode * r){
        if(r == NULL)
            return;

        store(r->left);
        v.push_back(r->val);
        store(r->right);
    }

    TreeNode* create(int s, int e, int m){
        if(s > e)
            return NULL;

        TreeNode * cur = new TreeNode(v[m]);
        cur->left = create(s, m-1, (s + m-1)/2);
        cur->right = create(m + 1, e, (m + 1 + e)/2);

        return cur;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        store(root);

        int s = 0, e = v.size() - 1, m = (s + e)/2;

        TreeNode * ans = create(s, e, m);

        return ans;
    }
};