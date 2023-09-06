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

    int ans = 0;

    pair<int, int> solve(TreeNode* r){
        if(r == NULL)
            return {0, 0};

        pair<int, int> a = solve(r->left),
        b = solve(r->right);

        if((a.first + b.first + r->val)/(1 + a.second + b.second) == r->val)
            ans++;

        return {(a.first + b.first + r->val), (1 + a.second + b.second)};
    }

    int averageOfSubtree(TreeNode* root) {
        pair<int, int> res = solve(root);

        return ans;
    }
};