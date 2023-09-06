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
        
        TreeNode * cur = new TreeNode(val);

        if(val < head->val){
            if(head->left == NULL)
                head->left = cur;
            else
                insert(head->left, val);
        }
        else{
            if(head->right == NULL)
                head->right = cur;
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