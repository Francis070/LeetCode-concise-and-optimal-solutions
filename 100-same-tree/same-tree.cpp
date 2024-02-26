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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL){
            if(p != q)
                return false;
            return true;
        }
        bool ans = true;
        if(p->val == q->val){
            ans = ans & isSameTree(p->left, q->left);
            ans = ans & isSameTree(p->right, q->right);
        }
        else{
            ans = false;
        }

        return ans;
    }
};