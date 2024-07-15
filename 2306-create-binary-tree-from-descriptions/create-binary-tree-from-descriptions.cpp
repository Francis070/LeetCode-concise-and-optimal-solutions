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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        int n = desc.size();
        map<int, TreeNode *> mp;
        set<int> st;
        for(int i =0; i < n; i++){
            TreeNode * par, * chi;
            if(mp.find(desc[i][0]) == mp.end()){
                par = new TreeNode(desc[i][0]);
                mp[desc[i][0]] = par;
            }
            else
                par = mp[desc[i][0]];

            if(mp.find(desc[i][1]) == mp.end()){
                chi = new TreeNode(desc[i][1]);
                mp[desc[i][1]] = chi;
            }
            else 
                chi = mp[desc[i][1]];

            if(desc[i][2]){
                par->left = chi;
            }
            else{
                par->right = chi;
            }

            st.insert(desc[i][0]);
            // if(st.find(desc[i][1]) != st.end())
            //     st.erase(desc[i][1]);
        }

        for(int i =0; i < n; i++){
            if(st.find(desc[i][1]) != st.end())
                st.erase(desc[i][1]);
        }

        int par = *st.begin();
        return mp[par];
    }
};