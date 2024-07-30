class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();

        int ca = 0, cb = 0;
        int ans = INT_MAX;
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++){
            if(s[i] == 'a') ca++;
            if(s[i] == 'b') cb++;

            if(i > 0){
                if(s[i] == 'a' ){
                    if(cb > 0)
                        dp[i] = min(cb, dp[i-1] + 1);
                    else 
                        dp[i] = dp[i-1];
                }
                else{
                    dp[i] = dp[i-1];
                }
            }
        }

        return dp[n-1];
    }
};