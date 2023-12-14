class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> diff(n, vector<int>(m, 0));
        vector<int> row(n, 0), col(m, 0);

        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < m; j++)
                if(grid[i][j]) cnt++;
            row[i] = cnt;
        }

        for(int i = 0; i < m; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++)
                if(grid[j][i]) cnt++;
            col[i] = cnt;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                diff[i][j] = (row[i] - (m - row[i])) + (col[j] - (n - col[j]));
            }
        }
        return diff;
    }
};