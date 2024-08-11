class Solution {
public:

    map<int, vector<int>> col, row;

    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void bfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& vis){
        col.clear();
        row.clear();
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({x, y});

        col[y].push_back(x);
        row[x].push_back(y);

        while(!q.empty()){
            pair<int, int> cur = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int a = cur.first + dir[i].first;
                int b = cur.second + dir[i].second;

                if(a >= 0 && a < n && b >= 0 && b < m && !vis[a][b] && grid[a][b]){
                    vis[a][b] = 1;
                    q.push({a,b});
                    col[b].push_back(a);
                    row[a].push_back(b);
                }
            }
        }
    }

    int numOfComp(vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    bfs(i, j, grid, vis);
                    cnt++;
                }
            }
        }

        return cnt;
    }

    bool checkTotSep(int x, int y, vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();

        if(y - 1 >= 0 && y + 1 < m && (grid[x][y -1] + grid[x][y + 1] == 2)){
            int ss = 0;
            for(int i = 0; i < n; i++){
                ss += grid[i][y];
            }

            if(ss == 1)
                return true;
            else 
                return false;
        }
        else if(x - 1 >= 0 && x + 1 < n && (grid[x-1][y] + grid[x + 1][y] == 2)){
            int ss = 0;
            for(int i = 0; i < m; i++){
                ss += grid[x][i];
            }

            if(ss == 1)
                return true;
            else 
                return false;
        }

        return false;
    }

    int minDays(vector<vector<int>>& grid) {
        int cnt = numOfComp(grid);
        int n = grid.size(), m = grid[0].size();
        // cout<<cnt;
        if(cnt != 1)
            return 0;

        if(col.size() == 1 || row.size() == 1){
            // cout<<"here";
            if(col.size() == 1){
                int rs = row.size();
                if(rs > 2){
                    return 1;
                }
                else{
                    return rs;
                }
            }
            else{
                int cs = col.size();
                if(cs > 2){
                    return 1;
                }
                else 
                    return cs;
            }
        }

        int ans = 4;
        for(int i = 0; i < n; i++){
            for(int j = 0; j  < m; j++){
                if(grid[i][j]){
                    int cc = 0;
                    for(int k = 0; k < 4; k++){
                        int x = i + dir[k].first;
                        int y = j + dir[k].second;

                        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y]){
                            cc++;
                        }
                    }
                    // bool chk = checkTotSep(i, j, grid);
                    // if(cc == 2 && checkTotSep(i, j, grid))
                    //     cc = 1;
                    grid[i][j] = 0;
                    int cn = numOfComp(grid);
                    grid[i][j] = 1;
                    if(cn > 1)
                        ans = 1;
                    ans = min(ans, cc);
                }
            }
        }

        return ans;
    }
};