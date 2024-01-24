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

    int count_pseudo_paths(TreeNode * root, unordered_map<int, int> um){
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            um[root->val]++;
            //check for palindrome.
            int cnt_even = 0, cnt_odd = 0;
            for(auto & x : um){
                if(x.second % 2 == 0)
                    cnt_even ++;
                else
                    cnt_odd++;
            }

            if(cnt_odd > 1)
                return 0;
            else
                return 1;
        }
        

        um[root->val]++;
        int cnt_left = count_pseudo_paths(root->left, um);
        int cnt_right =count_pseudo_paths(root->right, um);

        return cnt_left + cnt_right;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int, int> um;
        int ans = count_pseudo_paths(root, um);

        return ans;
    }
};