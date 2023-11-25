class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<int> west(n, 0), north(m, 0);

        for(int i = 0; i < n; i ++){
            int cur = 0;
            for(int j = 0; j < m; j++){
                cur = max(cur, grid[i][j]);
            }
            west[i] = cur;
        }

        for(int i =0; i < m; i++){
            int cur = 0;
            for(int  j = 0; j < n; j++){
                cur = max(cur, grid[j][i]);
            }
            north[i] = cur;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] < (min(west[i], north[j])))
                    ans += min( west[i], north[j] ) - grid[i][j];
            }
        }

        return ans;
    }
};