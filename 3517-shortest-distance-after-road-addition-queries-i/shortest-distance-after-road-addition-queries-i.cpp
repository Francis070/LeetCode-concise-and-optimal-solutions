class Solution {
public:

    int bfs(int src, int des, int n, vector<vector<int>> & adj){
        vector<int> vis(n, 0);

        vis[src] = 1;

        queue<pair<int, int>> q;
        q.push({src, 0});
        // int t = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int, int> cur = q.front();
                q.pop();

                for(auto & x : adj[cur.first]){
                    if(!vis[x]){
                        if(x == des){
                            return (cur.second + 1);
                        }
                        else{
                            q.push({x, cur.second + 1});
                        }
                        vis[x] =1;
                    }
                }
            }
        }

        return 0;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);

        for(int i = 0; i < n-1; i++){
            adj[i].push_back(i + 1);
        }
        int m = queries.size();
        vector<int> ans;
        for(int i = 0; i < m; i++){
            int u = queries[i][0], v = queries[i][1];

            adj[u].push_back(v);

            int cur = bfs(0, n-1, n, adj);
            ans.push_back(cur);
        }

        return ans;
    }
};