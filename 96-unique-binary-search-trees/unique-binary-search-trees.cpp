class Solution {
public:
    int numTrees(int n) {
        if(n < 3)   
            return n;
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i <= n; i++){
            int val = 0;
            for(int j = 1; j <= i; j++){
                val += dp[i - j] * dp[j - 1];
            }
            // cout<<val;
            dp[i] = val;
        }
        return dp[n];
    }
};