#define ll long long
class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<ll>> dp(n + 2, vector<ll>(k + 2, 0));
        
        for(int i= 0; i <= n; i++){
            dp[i][0] = 1; 
        }
        int mod = 1e9 + 7;
        for(int i = 1; i <= n; i++){
            // for(int j = 1; j <= k; j++){
            //     if(j < i){
            //         dp[i][j] = (dp[i][j-1] + dp[i-1][j])%mod;
            //     }
            //     else{
            //         dp[i][j] = ( - dp[i][j-i])%mod;
            //     }
            // }

            for(int j = 1; j <= k; j++){
                if(j < i){
                    dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
                }
                if(j >= i){
                    dp[i][j] = (1000000007 + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-i])%mod;
                }
            }
        }

        return dp[n][k]%mod;
    }
};