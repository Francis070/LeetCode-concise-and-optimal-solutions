class Solution {
public:

    void dfs(int src, int val, vector<int> & vis, vector<vector<int>> &adj){
        vis[src] = val;

        for(auto x : adj[src]){
            if(vis[x] == -1){
                vis[x] = val;
                dfs(x, val, vis, adj);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> vis(n, -1);

        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i = 0; i < n; i++){
            if(vis[i] == -1){
                dfs(i, i, vis, adj);
            }
        }

        if(vis[source] == vis[destination])
            return true;
        return false;
    }
};