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
#define ll long long

void get_sum(TreeNode * root, string cur, vector<ll> &v){
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL){
        cur += char('0'+root->val);
        v.push_back(stoi(cur));
        return;
    }

    get_sum(root->left, cur + char('0'+root->val), v);
    get_sum(root->right,  cur + char('0'+root->val), v);
}

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        vector<ll> v;

        // string cur = "";
        get_sum(root, "", v);
        int ans = 0;
        for(auto x : v){
            ans += x;
        }

        return ans;
    }
};