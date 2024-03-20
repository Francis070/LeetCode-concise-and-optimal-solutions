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
// vector represents = {sum, min, max, status}
    vector<int> get(TreeNode * root, int & ans){
        if(root == NULL)
            return {0, INT_MAX, INT_MIN, 1};

        vector<int> l = get(root->left, ans);
        vector<int> r = get(root->right, ans);
        vector<int> temp(4, 0);
        int cur = root->val;
        if(l[3] == 1 && r[3] == 1 && cur > l[2] && cur < r[1]){
            ans = max(ans, l[0] + r[0] + cur);
            temp[0] = l[0] + r[0] + cur;
            temp[1] = min({l[1], r[1], cur});
            temp[2] = max({l[2], r[2], cur});
            temp[3] = 1;
        }
        else{
            temp[0] = l[0] + r[0] + cur;
            temp[1] = min({l[1], r[1], cur});
            temp[2] = max({l[2], r[2], cur});
            temp[3] = 0;
        }

        return temp;
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        
        vector<int> cur = get(root, ans);

        return ans;
    }
};