class Solution {
public:
    int maxA(int n) {
        vector<long long> dp(n + 1, 0);

        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = i;
            int cnt = 2;
            for(int j = i - 3; j >= 1; j--){
                dp[i] = max(dp[i], dp[j] * cnt);
                cnt++;
            }
        }

        return dp[n];
    }
};