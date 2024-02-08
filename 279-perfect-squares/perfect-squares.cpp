class Solution {
public:
    int numSquares(int n) {

        vector<int> ps;
        for(int i = 1; i*i <= n; i++){
            ps.push_back(i*i);
        }

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i*i <= n; i++){
            dp[i*i]= 1;
        }

        for(int i = 1; i <= n; i++){
            if(dp[i] == INT_MAX){
                for(int j = 0; j < ps.size(); j++){
                    if(ps[j] <= i && dp[i - ps[j]] != INT_MAX){
                        dp[i] = min(dp[i], 1 + dp[i - ps[j]]);
                    }
                }
            }
        }

        return dp[n];
    }
};