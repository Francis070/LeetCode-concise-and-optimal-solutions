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
    bool isEvenOddTree(TreeNode* root) {
        
        queue<TreeNode *> q;
        q.push(root);
        int lev = 0;
        while(!q.empty()){
            int sz = q.size();

            if(lev == 0){
                int prev = -1;
                while(sz--){
                    TreeNode * cur = q.front();
                    q.pop();
                    int cval = cur->val;
                    if((cval % 2 == 1 )&& (cval > prev)){
                        prev = cval;
                        // q.push(cur);
                        if(cur->left != NULL) q.push(cur->left);
                        if(cur->right != NULL) q.push(cur->right);

                    }
                    else
                        return false;
                }
            }
            else{
                int prev = INT_MAX;
                while(sz--){
                    TreeNode * cur = q.front();
                    q.pop();
                    int cval = cur->val;
                    if((cval % 2 == 0) && (cval < prev)){
                        prev = cval;
                        if(cur->left != NULL) q.push(cur->left);
                        if(cur->right != NULL) q.push(cur->right);
                    }
                    else
                        return false;
                }
                
            }
            lev = (lev + 1)%2;
        }
        return true;
    }
};