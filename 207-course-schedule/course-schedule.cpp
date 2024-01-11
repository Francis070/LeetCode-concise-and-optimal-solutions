class Solution {
public:

    bool dfs(int src, vector<vector<int>> adj, vector<int> &vis, vector<int>&um){
        vis[src] = 1;
        // st.insert(src);
        um[src] = 1;
        bool ans = false;
        for(auto x : adj[src]){
            // if((vis[x] == 0 && st.find(x) == st.end()) || (vis[x] == 1 && st.find(x) == st.end())){
            //     st.insert(x);
            //     vis[x] = 1;
            //     ans = ans || dfs(x, adj, vis, st);
            // }
            // else{
            //     return true;
            // }
            if(vis[x] == 0){
                // st.insert(x);
                um[x] = 1;
                vis[x] = 1;
                ans = ans || dfs(x, adj, vis, um);
            }
            else{
                // if(st.find(x) != st.end())
                //     return true;

                if(um[x] == 1)  
                    return true;
            }
        }
        // st.erase(src);
        um[src] = 0;
        return ans;
    }

    bool canFinish(int nc, vector<vector<int>>& pq) {
        vector<vector<int>> adj(nc);

        for(int i = 0; i < pq.size(); i++){
            adj[pq[i][1]].push_back(pq[i][0]);
        }
        vector<int> vis(nc, 0), um(nc, 0);
        bool ans = false;

        for(int i = 0; i < nc; i++){
            if(!vis[i]){
                // set<int> st;/
                // unordered_map<int, int> um;
                ans = ans || dfs( i, adj, vis, um);
            }
        }

        return !ans;
    }
};