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
    unordered_set<int> st;
    int top, cnt;
    TreeNode * prev;

    void rec(TreeNode * root){
        if(root == NULL)
            return;
        //left
        rec(root->left);
        // prev = root->left;

        //mid
        if(prev != NULL){
            if(prev->val == root->val){
                cnt++;
            }
            else
                cnt = 1;
            if(cnt > top){
                top = cnt;
                st.clear();
                st.insert(root->val);
            }
            else if(cnt == top){
                st.insert(root->val);
            }
        }
        else{
            cnt = 1; top = max(top, 1);
            if(cnt == top)
                st.insert(root->val);
        }

        prev = root;
        //right
        rec(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        top = 0, cnt = 0, prev = NULL;
        rec(root);

        vector<int> ans;
        for(int x : st){
            ans.push_back(x);
        }
        return ans;
    }   
};