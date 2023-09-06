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

    void insert(TreeNode * head, int val){
        
        if(val < head->val && head->left == NULL){
            TreeNode * cur = new TreeNode(val);
            head->left = cur;
        }
        else if(val > head->val && head->right == NULL){
            TreeNode * cur = new TreeNode(val);
            head->right = cur;
        }
        else{
            if(val < head->val)
                insert(head->left, val);
            else
                insert(head->right, val);
        }
        return;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode * head = new TreeNode(preorder[0]);

        for(int i = 1; i < preorder.size(); i++)
            insert(head, preorder[i]);

        return head;
    }
};