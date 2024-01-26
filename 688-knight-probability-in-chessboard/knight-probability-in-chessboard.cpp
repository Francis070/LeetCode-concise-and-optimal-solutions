#define ll unsigned long long
class Solution {
public:
    vector<pair<int, int>> dirs = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    double rec(int i, int j, int k, int n,  vector<vector<vector<double>>> &dp){
        if(i < 0 || i >= n || j < 0 || j >= n)
            return 0;
        if(k == 0)
            return 1;

        if(dp[i][j][k] != -1)
            return dp[i][j][k];

        double cnt = 0;
        for(int s = 0; s < 8; s++){
           cnt += rec(i + dirs[s].first, j + dirs[s].second, k - 1, n, dp);
        }

        return dp[i][j][k] = (cnt * 1.0)/8.0;
    }

    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(n +1, vector<double>(k + 1, -1))); 
        double val = rec(row, column, k, n, dp);
        // // cout<<val;
        // double value = val * 1.0;
        // cout<<value;
        // for(int i = 0 ; i < k; i++){
        //     value = (value * 1.0)/(8.0);
        // }
        return val;
    }
};