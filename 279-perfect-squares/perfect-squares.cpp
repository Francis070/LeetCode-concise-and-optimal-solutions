class Solution {
public:
    int numSquares(int n) {
        vector<int> st;
        int k = 1;
        while(k*k <= n){
            st.push_back(k*k);
            k++;
        }

        vector<int> dp(n + 1, 1e8);
        dp[0] = 1;
        for(auto d : st){
            if(d <= n)
                dp[d] = 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < st.size(); j++){
                if(st[j] <= i && dp[i - st[j]] != 1e8){
                    dp[i] = min(dp[i], 1 + dp[i - st[j]]);
                }

            }
        }

        return dp[n];
    }
};