class Solution {
public:

    double dist(pair<int, int> a, pair<int, int> b){
        double dist = static_cast<double>(sqrt( (1.0 * pow(a.first - b.first, 2))  
        + (1.0 * pow(a.second - b.second, 2)) ) );

        return dist;
    }

    int bfs(int src, vector<vector<int>> &adj){
        vector<int> vis(adj.size(), 0);
        vis[src] = 1;

        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int x : adj[cur]){
                if(!vis[x]){
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }

        int cnt = 0;
        for(int x : vis)
            cnt += x;

        return cnt;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        // multimap<vector<int>, int> um;
        // for(int i = 0; i < n; i++){
        //     // um[bombs[i]] = i;
        //     um.insert({bombs[i], i});
        // }

        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){

            for(int j = 0; j < n; j++){
                if(j != i){
                    double far = dist({bombs[i][0], bombs[i][1]}, {bombs[j][0], bombs[j][1]});

                    if(far <= static_cast<double>(bombs[i][2])){
                        adj[i].push_back(j);
                    }
                }
            }
        }

        // 
        int ans = 0;

        for(int i = 0; i < n; i++){
            vector<int> vis(n, 0);

            int num = bfs(i, adj);
            ans= max(ans, num);
        }

        return ans;
    }
};