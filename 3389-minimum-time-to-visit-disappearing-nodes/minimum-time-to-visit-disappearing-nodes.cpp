#define ll long long
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<int> ans(n, -1);
        ans[0] = 0;
        vector<vector<pair<ll, ll>>> adj(n);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        
        int m = edges.size();
        
        for(int i = 0; i < m; i ++){
            ll u = edges[i][0];
            ll v = edges[i][1];
            ll w = edges[i][2];
            
            if(u != v){
                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
            }
        }
        
        vector<ll> dist(n, 1e12);
        dist[0] = 0;
        
        pq.push({0, 0});
        vector<bool>vis(n,0);
        while(!pq.empty()){
            ll node = pq.top().second;
            
            pq.pop();
            if(vis[node]==1)
                continue;
            vis[node] = 1;
            for(auto x : adj[node]){
                ll v = x.first;
                ll wt = x.second;
                
                if((dist[v] > (dist[node] + wt)) && ((dist[node] + wt) < disappear[v])){
                    dist[v] = dist[node] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        
        for(int i = 1; i < n; i++){
            if(dist[i] < disappear[i]){
                ans[i] = dist[i];
            }
        }
        
        return ans;
    }
};