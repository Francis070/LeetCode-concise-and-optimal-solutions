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

    static bool comp(pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    }

    void get_vertical_order(int ind, int level, TreeNode * root, vector<vector<pair<int, int>>> &ans){
        if(root == NULL){
            return;
        }

        ans[ind].push_back({level, root->val});
        get_vertical_order(ind - 1, level + 1, root->left, ans);
        get_vertical_order(ind + 1, level + 1, root->right, ans);
    }

    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<pair<int, int>>> ans(215);
        vector<vector<int>> res;
        int n = ans.size()/2;
        get_vertical_order(n,0, root, ans);

        for(int i = 0; i < ans.size(); i++){
            if(ans[i].size() != 0){
                // res.push_back(ans[i]);
                sort(ans[i].begin(), ans[i].end(), comp);
                vector<int> temp;
                for(int j = 0; j < ans[i].size(); j++){
                    temp.push_back(ans[i][j].second);
                }
                res.push_back(temp);
            }
        }

        return res;
    }
};