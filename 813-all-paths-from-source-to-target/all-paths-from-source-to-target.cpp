class Solution {
public:

    void rec(int ind, int n, vector<int> ds, vector<vector<int>> & v, vector<vector<int>>& graph){

        if(ind == n){
            v.push_back(ds);
            return;
        }

        if(graph[ind].size() == 0)
            return;
        // vis[ind] = 1;
        for(int i = 0; i < graph[ind].size(); i++){
            ds.push_back(graph[ind][i]);
            rec(graph[ind][i], n, ds, v, graph);
            ds.pop_back();
        }
        // vis[ind] = -1;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> v;
        vector<int> vis(graph.size(), -1);

        rec(0, graph.size()-1, {0}, v, graph);

        return v;

    }
};