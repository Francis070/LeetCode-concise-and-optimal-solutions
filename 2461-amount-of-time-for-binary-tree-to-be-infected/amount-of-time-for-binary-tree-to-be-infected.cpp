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

    void create_adjs(TreeNode * root, unordered_map<int, vector<int>> &adjs){
        if(root->left != NULL){
            adjs[root->val].push_back(root->left->val);
            adjs[root->left->val].push_back(root->val);
            create_adjs(root->left, adjs);
        }
        if(root->right != NULL){
            adjs[root->val].push_back(root->right->val);
            adjs[root->right->val].push_back(root->val);
            create_adjs(root->right, adjs);
        }
    }
    
    int amountOfTime(TreeNode* root, int start) {
        //create adjs

        unordered_map<int, vector<int>> adjs;
        create_adjs(root, adjs);

        // run bfs on the created graph

        set<int> visited;
        queue<int> q;
        q.push(start);
        visited.insert(start);
        int l = 0;
        while(!q.empty()){
            
            int sz = q.size();

            while(sz-- > 0){
                int cur = q.front();
                q.pop();
                for(int i = 0; i < adjs[cur].size(); i++){
                    if(visited.find(adjs[cur][i]) == visited.end()){
                        visited.insert(adjs[cur][i]);
                        q.push(adjs[cur][i]);
                    }
                }
            }
            if(q.size() > 0)
                l++;
        }

        return l;

        // for(auto & x : adjs){
        //     cout<<x.first<<"->";
        //     for(int i = 0; i < x.second.size(); i++){
        //         cout<<x.second[i]<<",";
        //     }
        //     cout<<endl;
        // }
        // return 0;
    }
};