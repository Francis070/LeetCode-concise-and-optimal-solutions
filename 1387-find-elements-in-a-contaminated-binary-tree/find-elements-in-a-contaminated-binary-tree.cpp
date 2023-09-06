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
class FindElements {
public:
    unordered_map<int, int> um;
    void recover(TreeNode * r, int v){
        if(r == NULL)
            return;

        r->val = v;
        um[v]++;
        recover(r->left, (2 * v) + 1);
        recover(r->right, (2 * v) + 2);
    }

    FindElements(TreeNode* root) {
        recover(root, 0);
    }
    
    bool find(int target) {
        if(um[target] > 0)
            return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */