class Solution {
public:

    vector<int> topo(vector<vector<int>> & adj, int k){
        vector<int> indegree(k + 1);

        for(int i = 1; i <= k; i++){
            for(int cur : adj[i]){
                indegree[cur]++;
            }
        }

        queue<int> q;
        vector<int> res;

        for(int i = 1; i <= k; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            res.push_back(cur);

            for(int x : adj[cur]){
                indegree[x]--;

                if(indegree[x] == 0){
                    q.push(x);
                }
            }
        }

        return res;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
        int n = rc.size(), m = cc.size();

        vector<vector<int>> radj(k + 1), cadj(k + 1);

        for(int i = 0; i < n; i++){
            int b = rc[i][0];
            int a = rc[i][1];

            radj[b].push_back(a);
        }

        for(int i = 0; i < m; i++){
            int b = cc[i][0];
            int a = cc[i][1];

            cadj[b].push_back(a);
        }

        vector<int> rodr = topo(radj, k);
        vector<int> codr = topo(cadj, k);

        if(rodr.size() < k || codr.size() < k){
            return {};
        }

        vector<vector<int>> res(k, vector<int>(k, 0));
        unordered_map<int, pair<int, int>> um;
        for(int i = 0; i < k; i++){
            if(um.find(rodr[i]) != um.end()){}

            um[rodr[i]] = {i, 0};
        }

        for(int i = 0; i < k; i++){
            um[codr[i]].second = i;
        }
        
        for(auto & x : um){
            res[x.second.first][x.second.second] = x.first;
        }

        return res;
    }   
};