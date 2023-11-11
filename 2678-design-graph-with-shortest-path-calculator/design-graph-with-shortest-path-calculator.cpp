class Graph {
public:
    vector<vector<pair<int, int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(int i = 0; i < edges.size(); i++)
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }

    int bfs(int src, int dest, vector<int> &vis){
        int ans = INT_MAX;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int cur = q.front();
            q.pop();

            if(cur == dest)
                ans = min(ans, vis[cur]);
            
            for(auto x : adj[cur]){
                if((vis[cur] + x.second) < vis[x.first]){
                    q.push(x.first);
                    vis[x.first] = vis[cur] + x.second;
                }
                else
                    continue;
            }
        }

        return ans;
    } 

    int shortestPath(int node1, int node2) {

        int n = adj.size();
        vector<int> vis(n, INT_MAX);
        vis[node1] = 0;
        int ans = bfs(node1, node2, vis);
        
        if(ans >= INT_MAX)
            return -1;
        return ans;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */