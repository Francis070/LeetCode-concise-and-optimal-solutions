class Solution {
public:

    int rec(int ind, int n , int amt, vector<int> &coin, vector<vector<int>> &dp){
        if(amt == 0 || ind >= n){
            if(amt == 0) return 1;
            return 0;
        }
        if(dp[ind][amt] != -1)
            return dp[ind][amt];
        int take = 0;
        if(coin[ind] <= amt)
            take = rec(ind, n, amt - coin[ind], coin, dp);
        int ntake = rec(ind + 1, n, amt, coin, dp);

        return dp[ind][amt] = take + ntake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+ 1, vector<int>(amount + 2, -1));

        return rec(0, n, amount, coins, dp);
    }
};