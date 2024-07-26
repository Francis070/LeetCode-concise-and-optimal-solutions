class Solution {
public:

    int bfs(int src, vector<vector<pair<int, int>>> & adj, int k){
        vector<int> vis(adj.size(), -1);

        vis[src] = 0;

        queue<pair<int, int>> q;
        q.push({src, 0});
        // vector<int> res;
        set<int> cf;
        int res = 0;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();

            int ver = cur.first, sum = cur.second;

            for(auto & x : adj[ver]){
                if((vis[x.first] == -1 && (k - sum >= x.second)) || ((vis[x.first] != -1) && (vis[x.first] > sum + x.second) && (sum + x.second <= k))){
                    vis[x.first] = sum + x.second;
                    // if(rem - x.second >= 0){
                        // res.push_back(x.first);
                        cf.insert(x.first);
                        res++;
                        q.push({x.first, sum + x.second});
                    // }
                }
            }
        }

        // sort(begin(cf), end(cf));

        // if(src == 30 || src == 33 || src == 7){
            // cout<<src<<endl;
            // for(int c : cf)
            //     cout<<c<<" ";
            // cout<<endl;
        // }

        return cf.size();
    }

    static bool comp(pair<int, int> a, pair<int, int> b){
        if(a.second == b.second){
            return a.first > b.first;
        }

        return a.second < b.second;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<pair<int, int>>> adj(n);

        for(auto x : edges){
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }

        // for(int i = 0; i < n; i++){
        //     cout<<i<<"-> ";
        //     for(auto x : adj[i]){
        //         cout<<x.first<<" "<<x.second<<", ";
        //     }
        //     cout<<endl;
        // }
 
        vector<pair<int, int>> res;

        for(int i = 0; i < n; i++){
            int val = bfs(i, adj, distanceThreshold);
            res.push_back({i, val});
        }

        sort(begin(res), end(res), comp);

        // for(auto & x : res){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }

        return res[0].first;
    }
};