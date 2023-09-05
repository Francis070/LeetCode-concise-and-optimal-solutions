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

    bool checkEqual(TreeNode * t1, TreeNode * t2){
        if(t1->val != t2->val)
            return false;

        bool ans = true;
        // if()
        if(t1->left != NULL && t2->left != NULL)
            ans = ans && checkEqual(t1->left, t2->left);
        if(t1->right != NULL && t2->right != NULL)
            ans = ans && checkEqual(t1->right, t2->right);
        if((t1->left == NULL && t2->left != NULL) || (t1->left != NULL && t2->left == NULL) || (t1->right != NULL && t2->right == NULL) || (t1->right == NULL && t2->right != NULL))
            ans = false;

        return ans;
    }
    bool ans = false;

    void tra(TreeNode* t1, TreeNode* t2){
        if(t1 == NULL)
            return;

        if(t1->val == t2->val){
            ans = ans || checkEqual(t1, t2);
        }

        tra(t1->left, t2); 
        tra(t1->right, t2);
    }

    bool isSubtree(TreeNode* t1, TreeNode* t2) {
        
        tra(t1, t2);

        return ans;

    }
};