class Solution {
public:

    bool check_bipartite(int source, vector<vector<int>> &graph, vector<int> &visited){

        queue<pair<int, int>> q;
        visited[source] = 0;

        q.push({source, 0});

        while(!q.empty()){
            pair<int, int> current = q.front();
            int node = current.first, value = current.second;
            q.pop();

            for(auto x : graph[node]){
                if(visited[x] == -1){
                    int new_value = (value+1)%2;
                    visited[x] = new_value;
                    q.push({x, new_value});
                }
                else if(visited[x] == value){
                    return false;
                }
            }
        }

        return true;
    }   

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> visited(n, -1);

        for(int i = 0; i < n; i++){
            if(visited[i] == -1 && !check_bipartite(i, graph, visited)){
                return false;
            }
        }

        return true;
    }
};