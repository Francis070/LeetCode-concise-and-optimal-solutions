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

    TreeNode* rec(int s, int e, vector<int> &nums){
        if(s > e)
            return NULL;

        int ind = -1, mx = -1;

        for(int i = s; i <= e; i++ )
            if(nums[i] > mx){
                mx = nums[i];
                ind = i;
            }
        
        TreeNode * cur = new TreeNode(mx);

        cur->left = rec(s, ind - 1, nums);
        cur->right = rec(ind + 1, e, nums);

        return cur;
        
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return rec(0, nums.size()-1, nums);
    }
};