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

    TreeNode * newTreeNode(int st, int en, vector<int> wv){
        if(st == en){
            TreeNode * ln = new TreeNode(wv[st], NULL, NULL);
            return ln;
        }
        if(st > en)
            return NULL;

        int mid = st + (en - st)/2;

        TreeNode * cnn = new TreeNode(wv[mid]);

        cnn->left = newTreeNode(st, mid - 1, wv);
        cnn->right = newTreeNode(mid + 1, en, wv);

        return cnn;
    }

    void getallvalues(TreeNode * root, vector<int> & av){
        if(root == NULL)
            return;

        getallvalues(root->left, av);
        getallvalues(root->right, av);

        av.push_back(root->val);
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> allvalues;
        
        getallvalues(root, allvalues);

        sort(begin(allvalues), end(allvalues));

        // for(int x : allvalues)
        //     cout<<x<<" ";

        TreeNode * ntn = newTreeNode(0, allvalues.size() - 1, allvalues);

        return ntn;
        // return NULL;
    }
};