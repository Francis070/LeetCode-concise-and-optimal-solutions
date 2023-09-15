class DisjointSet{
    vector<int> parent, size;
public:

    DisjointSet(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i =0 ; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionSet(int u, int v){
        int par_u = findParent(u);
        int par_v = findParent(v);
        if(par_u == par_v)
            return;

        if(size[par_u] > size[par_v]){
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
        else{
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        }
    }

};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<pair<int, pair<int, int>>> vp;
        for(int i =0 ; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                vp.push_back({dist, {i, j}});
            }
        }
        int ans = 0;
        sort(vp.begin(), vp.end());

        DisjointSet ds(n);
        for(int i = 0; i < vp.size(); i++){
            int wt = vp[i].first;
            int u = vp[i].second.first;
            int v = vp[i].second.second;

            if(ds.findParent(u) != ds.findParent(v)){
                ans += wt;
                ds.unionSet(u, v);
            }
        }

        return ans;
    }
};