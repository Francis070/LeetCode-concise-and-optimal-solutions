class Solution {
public:

    void dfs(int src, vector<vector<int>> & adj, vector<set<int>> & ans){

        for(auto & x : adj[src]){
            if(ans[x].size() == 0){
                dfs(x, adj, ans);
            }
            ans[src].insert(x);
            for(auto & y : ans[x]){
                ans[src].insert(y);
            }
        }

    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < m; i++){
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<set<int>> ans(n);

        for(int i =0; i < n; i++){
            dfs(i, adj, ans);
        }
        vector<vector<int>> va;
        for(int i = 0; i < n; i++){
            // sort(begin(ans[i]), end(ans[i]));
            vector<int> cur(ans[i].begin(), ans[i].end());
            va.push_back(cur);
        }

        return va;
    }
};