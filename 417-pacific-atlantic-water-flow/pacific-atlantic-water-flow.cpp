class Solution {
public:
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    void bfs(int x, int y, int ocn, vector<vector<pair<int, int>>> &chk, vector<vector<int>>& ht){
        queue<pair<int, int>> q;
        int n = ht.size(), m = ht[0].size();
        q.push({x, y});
        while(!q.empty()){
            pair<int, int> cur = q.front();
            q.pop();

            for(int i =0; i < 4; i++){
                int a = cur.first + dirs[i].first;
                int b = cur.second + dirs[i].second;
                
                if(a >= 0 && a < n && b >= 0 && b < m){
                    if(ocn == 1){
                        if((ht[cur.first][cur.second] <= ht[a][b]) && (chk[a][b].first == 0)){
                            chk[a][b].first = 1;
                            q.push({a, b});
                        }
                    }
                    else if(ocn == 2){
                        if((ht[cur.first][cur.second] <= ht[a][b]) && (chk[a][b].second == 0)){
                            chk[a][b].second = 1;
                            q.push({a, b});
                        }
                    }
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& ht) {
        int n = ht.size();
        int m = ht[0].size();

        vector<vector<int>> ans;
        vector<vector<pair<int, int>>> chk(n, vector<pair<int, int>>(m, {0, 0}));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if((i == 0 || j == 0) && (i == n-1 || j == m-1)){
                        chk[i][j].first = 1;
                        chk[i][j].second = 1;
                        bfs(i, j, 1, chk, ht);
                        bfs(i, j, 2, chk, ht);
                    }
                    else if(i == 0 || j == 0){
                        chk[i][j].first = 1;
                        bfs(i, j, 1, chk, ht);
                    }
                    else if(i == n-1 || j == m-1){
                        chk[i][j].second = 1;
                        bfs(i, j, 2, chk, ht);
                    }
                }
                else{
                    continue;
                }
            }
        }

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j< m; j++){
        //         cout<<"("<<chk[i][j].first<<","<<chk[i][j].second<<") ";
        //     }
        //     cout<<endl;
        // }

        for(int i = 0; i < n; i++){
            for(int j = 0; j< m; j++){
                if(chk[i][j].first && chk[i][j].second){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};