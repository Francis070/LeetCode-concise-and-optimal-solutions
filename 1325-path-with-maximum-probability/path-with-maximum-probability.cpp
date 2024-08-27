class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        vector<double> prob(n, 0.0);

        int m = edges.size();
        for(int i = 0; i < m; i++){
            int u = edges[i][0], v = edges[i][1];
            double w = succProb[i];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<double, int>> pq;

        pq.push({1, start_node});
        prob[start_node] = 1.0;

        while(!pq.empty()){
            auto tp = pq.top();
            pq.pop();

            double wt = tp.first;
            int node = tp.second;

            for(auto & x : adj[node]){
                if((wt * x.second) > prob[x.first]){
                    prob[x.first] = wt * x.second;
                    pq.push({wt * x.second, x.first});
                }
            }
        }

        return prob[end_node];
    }
};