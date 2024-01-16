class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> v(n, vector<int>(m, 0));

        for(int i = 0; i < m; i++){
            if(grid[0][i])
                break;
            v[0][i] = 1;
        }
        for(int i = 0; i < n; i++){
            if(grid[i][0])
                break;
            v[i][0] = 1;
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j< m; j++){
                if(!grid[i][j]){
                    if(!grid[i-1][j])
                        v[i][j] += v[i-1][j];
                    if(!grid[i][j-1])
                        v[i][j] += v[i][j-1];
                }
                
            }
        }

        return v[n-1][m-1];
    }
};