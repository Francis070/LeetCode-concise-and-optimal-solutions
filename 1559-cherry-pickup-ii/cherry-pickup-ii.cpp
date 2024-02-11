class Solution {
public:
    vector<pair<int, int>> dirs = {{1, -1}, {1, 0}, {1, 1}};

    bool valid(int x, int y, int n, int m){
        if(x <0 || x >= n || y < 0 || y >= m)
            return false;
        return true;
    }

    bool common(int x1, int y1, int x2, int y2){
        if(x1 == x2 && y1 == y2)
            return true;

        return false;
    }

    int pick_cherry(pair<int, int> first_bot, pair<int, int> second_bot, vector<vector<int>>& grid, 
    vector<vector<vector<vector<int>>>> &dp){
        if(first_bot.first >= grid.size() && second_bot.first >= grid.size()){
            return 0;
        }

        if(dp[first_bot.first][first_bot.second][second_bot.first][second_bot.second] != -1)
            return dp[first_bot.first][first_bot.second][second_bot.first][second_bot.second];
        //explore all options but no overlap
        //move both bots
        int ans = 0;
        int n = grid.size(), m = grid[0].size();

        for(int i = 0; i < 3; i++){
            int x1 = first_bot.first + dirs[i].first, y1 = first_bot.second + dirs[i].second;
            if(!valid(x1, y1, n, m))
                continue;
            for(int j = 0; j < 3; j++){
                int x2 = second_bot.first + dirs[j].first, y2 = second_bot.second + dirs[j].second;
                if(!valid(x2, y2, n, m))
                    continue;

                if(common(x1, y1, x2, y2)){
                    ans = max(ans, grid[x1][y1] + pick_cherry({x1, y1}, {x2, y2}, grid, dp));
                }
                else{
                    ans = max(ans, grid[x1][y1] + grid[x2][y2] + pick_cherry({x1, y1}, {x2, y2}, grid, dp));
                }
            }
        }

        return dp[first_bot.first][first_bot.second][second_bot.first][second_bot.second] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<vector<int>>>> dp(n + 2, vector<vector<vector<int>>>(m + 2, vector<vector<int>>(n + 2, vector<int>(m + 2, -1))));

        int ans = grid[0][0] + grid[0][m-1] + pick_cherry({0, 0}, {0, m-1}, grid, dp);

        return ans;
    }
};