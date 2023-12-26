class Solution {
public:
    int mod = 1e9 + 7;
    
    long long rec(long long n, long long k, long long target, vector<vector<int>> &dp){
        if(target == 0 && n == 0){
            return 1;
        }
        if(n <= 0 || target <= 0){
            return 0;
        }

        if(dp[n][target] != -1)
            return dp[n][target];

        long long ans = 0;

        for(int i = 1; i <= k; i++)
            ans = (ans + rec(n-1, k, target - i, dp)) % mod;

        return dp[n][target] = ans%mod;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+ 1, vector<int>(target + 1, -1));
        long long ans = rec(n, k, target, dp);
        return ans%mod;
    }
};