class Solution {
public:

    void dfs(int src, unordered_set<int> &st, 
    vector<int> &vis, vector<int> path, vector<int> pe, 
    vector<vector<int>>& graph){
        vis[src] = 1;
        path[src] = 1;
        pe.push_back(src);

        for(auto x : graph[src]){
            if(!vis[x]){
                // pe.push_back(x);
                dfs(x, st, vis, path, pe, graph);
                // pe.pop_back();
            }
            else{
                if(path[x] || st.find(x) == st.end()){
                    for(int i = 0; i < pe.size(); i++){
                        if(st.find(pe[i]) != st.end())
                            st.erase(pe[i]);
                    }
                }
            }
        }
        pe.pop_back();
        path[src] = 0;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0), path(n, 0);

        unordered_set<int> st;

        for(int i = 0; i < n; i++)
            st.insert(i);

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, st, vis, path, {}, graph);
            }
        }

        vector<int> ans;
        for(auto x : st)
            ans.push_back(x);
        sort(ans.begin(), ans.end());
        return ans;
    }
};