class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        if(source == target)
            return 0;

        unordered_map<int, vector<int>> um;
        set<int> vis;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < routes[i].size(); j++){
                um[routes[i][j]].push_back(i);
            }
        }

        vector<int> q;

        for(int i = 0; i < um[source].size(); i++){
            q.push_back(um[source][i]);
            vis.insert(um[source][i]);
        }
        int cnt = 1;
        bool dest = false;
        while(q.size() > 0){
            int sz = q.size();
            vector<int> temp;
            for(int i = 0; i < sz; i++){
                int rn = q[i];
                for(int j = 0; j < routes[rn].size(); j++){
                    if(routes[rn][j] == target){
                        return cnt;
                    }
                    else{
                        int node = routes[rn][j];
                        for(int k = 0; k < um[node].size(); k++){
                            if(vis.find(um[node][k]) == vis.end()){
                                // q.push_back(um[node][k]);
                                temp.push_back(um[node][k]);
                                vis.insert(um[node][k]);
                            }
                        }
                    }
                }
            }
            q.clear();
            q = temp;
            temp.clear();
            // while(sz > 0){
            //     q.erase(q.begin());
            //     sz--;
            // }
            cnt++;
        }

        return -1;
    }
};