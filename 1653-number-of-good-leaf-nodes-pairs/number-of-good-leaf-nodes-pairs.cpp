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

    vector<int> getPairs(TreeNode * root, int dist, int & ans){
        if(root == NULL){
            return {};
        }

        vector<int> lft = getPairs(root->left, dist, ans);
        vector<int> rgt = getPairs(root->right, dist, ans);

        // cout<<root->val<<endl;
        // for(int x : lft)
        //     cout<<x<<" ";
        // cout<<endl;
        // for(int x : rgt)
        //     cout<<x<<" ";
        // cout<<endl;

        if(lft.size() == 0 && rgt.size() == 0)
            return {1};
        else {
            sort(begin(lft), end(lft));
            sort(begin(rgt), end(rgt));

            for(int x : lft){
                int y = dist - x;
                if(dist < 0){
                    break;
                }
                else{
                    int ps = upper_bound(begin(rgt), end(rgt), y) - begin(rgt);
                    ans += ps;
                }
            }
        }

        vector<int> ret;
        for(int x : lft)
            ret.push_back(x + 1);
        for(int x : rgt)
            ret.push_back(x + 1);

        return ret;
    }

    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        vector<int> v = getPairs(root, distance, ans);

        return ans;
    }       
};