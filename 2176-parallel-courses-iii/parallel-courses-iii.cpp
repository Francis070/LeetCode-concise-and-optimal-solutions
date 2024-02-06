class Solution {
public: 

    int vis[100004];

    int dfs(int src, vector<vector<int>> &adj, vector<int>& time, vector<int> &dp){
        
        int cur = 0;
        vis[src] = 1;

        for(int i : adj[src]){
            if(vis[i] == 0){
                cur = max(cur, dfs(i, adj, time, dp));
            }
            else{
                cur = max(cur, dp[i]);
            }
        }

        return dp[src] = cur + time[src];
    }

    vector<int> get_sources(int n, vector<vector<int>>& relations){
        vector<int> res(n, 0);
        int m = relations.size();

        for(int i = 0; i < m; i++)
            res[relations[i][1] - 1]++;
        
        vector<int> ans;
        for(int  i = 0;i < n; i++)
            if(res[i] == 0)
                ans.push_back(i);
        
        return ans;
    }

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int m = relations.size();
        vector<int> sources = get_sources(n, relations);

        vector<vector<int>> adj(n);

        for(int i = 0; i < m; i++){
            adj[relations[i][0] - 1].push_back(relations[i][1] - 1);
        }

        int ans = 0;
        vector<int> dp(n, -1);
        for(int i = 0; i < sources.size(); i++){
            ans = max(ans, dfs(sources[i], adj, time, dp));
        }

        return ans;
    }
};