class Solution {
public:

    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>> &vis){
        vis[x][y] = 1;
        // cout<<grid[x][y]<<" ";
        int n = grid.size(), m = grid[0].size();
        int local = INT_MIN;
        for(int i =0; i < 4; i++){
            int a = x + dirs[i].first;
            int b = y + dirs[i].second;

            if(a >= 0 && a < n && b >= 0 && b < m && vis[a][b] == 0 && grid[a][b] > 0){
                local = max(local, grid[x][y] + dfs(a, b, grid, vis));
            }
        }


        vis[x][y] = 0;
        return max(local, grid[x][y]);
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0){
                    vector<vector<int>> vis(n, vector<int>(m, 0));
                    int calc = dfs(i, j, grid, vis);
                    ans = max(ans, calc);
                }
            }
        }

        return max(0, ans);
    }
};