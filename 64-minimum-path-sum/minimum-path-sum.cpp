class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
         vector<vector<int>> v(n, vector<int>(m, 0));
         v[0][0] = grid[0][0];
        for(int i = 1; i < m; i++){
            v[0][i] = v[0][i-1] + grid[0][i];
        }
        for(int i = 1; i < n; i++){
            v[i][0] = v[i-1][0] + grid[i][0];
        }

        for(int i = 1; i < n;i++){
            for(int j = 1; j < m; j++){
                v[i][j] = grid[i][j] + min(v[i-1][j], v[i][j-1]);
            }
        }

        return v[n-1][m-1];
    }
};