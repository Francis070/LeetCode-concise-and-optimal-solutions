class Solution {
public:

    int rec(int ind, int n, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(amount == 0 || ind >= n){
            if(amount == 0)
                return 1;
            else
                return 0;
        }
        if(dp[ind][amount] != -1)
            return dp[ind][amount];
        int ans = 0;

        for(int i =ind; i < n; i++){
            if(amount - coins[i] >= 0){
                ans += rec(i, n, amount - coins[i], coins, dp);
            }
        }

        return dp[ind][amount] = ans;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 5, -1));

        return rec(0, n, amount, coins, dp);
    }
};