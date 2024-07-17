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

class twp{
public:
    TreeNode * parent;
    TreeNode * node;
    int val;
    TreeNode * left;
    TreeNode * right;

    twp(){
        this->parent = NULL;
        this->node = NULL;
        this->val = 0;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution {
public:

    void getChild(TreeNode * root, map<int, pair<TreeNode *, TreeNode *>> & mp, map<int, int> &level, map<int, TreeNode *> & vn, int lev, TreeNode * par, map<int, twp *> & rln){
        if(root == NULL)
            return;
        
        mp[root->val] = {root->left, root->right};
        level[root->val] = lev;
        vn[root->val] = root;
        twp * cur = new twp();
        cur->parent = par;
        cur->val = root->val;
        cur->node = root;
        cur->left = root->left;
        cur->right = root->right;
        rln[root->val] = cur;
        getChild(root->left, mp, level, vn, lev + 1, root, rln);
        getChild(root->right, mp, level, vn, lev + 1, root, rln);
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> st;
        st.insert(root->val);
        vector<TreeNode *> ans;
        int n = to_delete.size();
        map<int, pair<TreeNode *, TreeNode *>> mp;
        map<int, int> level;
        map<int, TreeNode *> vn;
        map<int, twp *> rln;
        getChild(root, mp, level, vn, 0, NULL, rln);

        vector<pair<int, int>> vp;
        for(int i =0; i < n; i++){
            vp.push_back({level[to_delete[i]], to_delete[i]});
        }

        sort(begin(vp), end(vp));

        for(int i = 0; i < n; i++){
            int cv = vp[i].second;

            //to delete
            //add not-null childs
            if(mp[cv].first != NULL){
                st.insert(mp[cv].first->val);
            }
            if(mp[cv].second != NULL){
                st.insert(mp[cv].second->val);
            }
            //check if the value is there in set, if yes then delete it.

            if(st.find(cv) != st.end()){
                st.erase(cv);
            }

            twp * rt = rln[cv];
            TreeNode * p = rt->parent;
            if(p != NULL && p->left != NULL && p->left->val == cv){
                p->left = NULL;
            }
            if(p != NULL && p->right != NULL && p->right->val == cv){
                p->right = NULL;
            }

        }

        for(auto f: st){
            ans.push_back(vn[f]);
        }

        return ans;
    }
};