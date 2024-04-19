class Solution {
public:

    void remove(int x, int y, vector<vector<char>>& grid){
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();

        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        q.push({x, y});
        grid[x][y] = '0';
        while(!q.empty()){
            pair<int, int> cur = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int a = cur.first + dirs[i].first;
                int b = cur.second + dirs[i].second;

                if(a >= 0 && a < n && b >= 0 && b < m && grid[a][b] == '1'){
                    grid[a][b] = '0';
                    q.push({a, b});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n;  i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    ans ++;
                    remove(i, j, grid);
                }
            }
        }

        return ans;
    }
};