class Solution {
public:

    int rec(int target, vector<int> &dp){
        if(target <= 1)
            return 1;
        if(dp[target] != -1)
            return dp[target];
        int ans = 0;
        for(int i = 1; i < target; i++){
            ans = max(ans, max(i * rec(target - i, dp), i * (target - i)) );
        }

        return dp[target] = ans;
    }

    int integerBreak(int n) {
        vector<int> dp(n + 1, -1);
        // dp[1] = 1;
        
        // for(int i = 2; i <= n; i++){
        //     int mx = 0;
        //     for(int j = 1; j <= i/2; j++){
        //         mx = max((i-j) * j, dp[i - j] * dp[j]);
        //     }
        //     dp[i] = mx;
        // }

        int ans = rec(n, dp);

        return ans;
    }
};