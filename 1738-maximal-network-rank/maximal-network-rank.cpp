class Solution {
public:

    vector<vector<int>> create_adj_list(int n, vector<vector<int>>& roads){
        vector<vector<int>> adj(n);

        for(int i = 0; i < roads.size(); i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }

        for(auto & x : adj){
            sort(x.begin(), x.end());
        }

        return adj;
    }

    bool connected(int a, int b, vector<vector<int>> &adj){
        if(binary_search(adj[a].begin(), adj[a].end(), b))
            return true;
        return false;
    }

    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj = create_adj_list(n, roads);
        int ans = 0; 
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                //check if they are connected.
                int temp = adj[i].size() + adj[j].size();

                if(connected(i, j, adj))
                    temp -= 1;

                ans = max(ans, temp);
            }
        }

        return ans;
    }
};