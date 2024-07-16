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

    bool desc(TreeNode * n1, TreeNode * n2){
        if(n1 == NULL){
            return 0;
        }
        
        if(n1 == n2)
            return 1;
            
        bool res = 0;
        res = res | desc(n1->left, n2);
        res = res | desc(n1->right, n2);
        
        return res;
    }

    void get(TreeNode * root, int val, TreeNode * & np1, vector<TreeNode * > & nv1){
        if(root == NULL){
            return;
        }
        
        if(np1 != NULL)
            return;
        
        if(root->val == val){
            np1 = root;
            nv1.push_back(root);
            return;
        }
        
        get(root->left, val, np1, nv1);
        
        get(root->right, val, np1, nv1);
        
        if(np1 != NULL){
            nv1.push_back(root);
        }
    }

    void getPath(TreeNode * st, TreeNode * desc, string & gt, bool & got){
        if(st == NULL){
            return;
        }

        if(got)
            return;

        if(st == desc){
            got = true;
            return;
        }

        getPath(st->left, desc, gt, got);
        if(got){
            gt += 'L';
            return;
        }

        getPath(st->right, desc, gt, got);
        if(got){
            gt += 'R';
            return;
        }
        
    }

    string getU(string a){
        int l = a.size();
        string ret = "";

        for(int i =0; i <l; i++)
            ret+= 'U';

        return ret;
    }

    string getDirections(TreeNode* root, int n1, int n2) {
        TreeNode * np1 = NULL;
        TreeNode * np2 = NULL;
        vector<TreeNode * > nv1, nv2;
        get(root, n1, np1, nv1);
        get(root, n2, np2, nv2);
        
        string ua;
        if(desc(np1, np2)){
            string ans = "";
            bool got = false;
            getPath(np1, np2, ans, got);
            reverse(begin(ans), end(ans));
            ua = ans;
            // return ans;
        }
        else if(desc(np2, np1)){
            string ans = "";
            bool got = false;
            getPath(np2, np1, ans, got);

            ua = getU(ans);
            // return np2;
        }
        else{
            set<TreeNode *> fr;
            for(auto & x : nv1)
                fr.insert(x);
            TreeNode * lca = NULL;
            for(auto & x : nv2){
                if(fr.find(x) != fr.end()){
                    lca = x;
                    break;
                }
            }

            string re = "";

            string fg = "", gf = "";
            bool got = false;
            getPath(lca, np1, fg, got);
            got = false;
            getPath(lca, np2, gf, got);
            reverse(begin(gf), end(gf));
            re = getU(fg) + gf;
            ua = re;
        }


        return ua;
    }
};