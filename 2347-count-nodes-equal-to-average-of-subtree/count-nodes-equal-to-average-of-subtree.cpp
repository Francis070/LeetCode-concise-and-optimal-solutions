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
    int ans;

    pair<int, int> rec(TreeNode * root){
        if(root == NULL){
            return {0, 0};
        }

        pair<int, int> left_subtree = rec(root->left);
        pair<int, int> right_subtree = rec(root->right);

        int tot_cnt = left_subtree.first + right_subtree.first + 1;
        int tot_sum = left_subtree.second + right_subtree.second + root->val;
        
        if((tot_sum/tot_cnt) == root->val){
            // cout<<tot_cnt<<" "<<tot_sum<<" "<<root->val<<endl;
            ans++;
        }

        return {tot_cnt, tot_sum};
    }

    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        pair<int, int> a = rec(root);

        return ans;
    }
};