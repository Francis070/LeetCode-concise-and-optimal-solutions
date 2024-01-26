#define ll long long
class Solution {
public:
    int mod = 1e9 + 7;
    ll rec(int i, int j, int m, int n, int mxm, vector<vector<vector<ll>>> &dp){
        if(i == m || i < 0 || j == n || j< 0) return 1;
        if(mxm <= 0) return 0;

        if(dp[i][j][mxm] != -1)
            return dp[i][j][mxm];

        ll curr = (rec(i, j + 1, m, n, mxm - 1, dp) + 
                     rec(i, j - 1, m, n, mxm - 1, dp) + 
                      rec(i - 1, j , m, n, mxm - 1, dp) + 
                       rec(i + 1, j, m, n, mxm - 1, dp) ) % mod;
        
        return dp[i][j][mxm] = curr;
    }

    int findPaths(int m, int n, int mxm, int str, int stc) {
        // vector<vector<ll>> dp(m, vector<ll> (n, -1));
        vector<vector<vector<ll>>> dp (m + 1, vector<vector<ll>>(n + 1, vector<ll>(mxm + 1, -1)));

        return rec(str, stc, m, n, mxm, dp);
    }
};