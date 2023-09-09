class Solution {
public:

    int rec(int index, int n, bool chk, int fee, vector<int> &prices, vector<vector<int>> & dp){
        if(index >= n)
            return 0;
        if(dp[index][chk] != -1)
            return dp[index][chk];

        int ans = 0;

        if(chk){   // case when I am allowed to buy the stock
            int buying = (-1 * prices[index]) + rec(index + 1, n, 0, fee, prices, dp);
            int notBuying =  rec(index + 1, n, 1, fee, prices, dp);

            ans = max(buying, notBuying);
        }
        else{    // case when I am allowed to sell the stock with a transaction fee.
            int selling = prices[index] +  rec(index + 1, n, 1, fee, prices, dp) - fee;   // reducing the transaction fee.
            int notSelling = rec(index + 1, n, 0, fee, prices, dp);
            ans = max(selling, notSelling);
        }

        return dp[index][chk] = ans;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 5, vector<int>(2, -1));
        int ans = rec(0, n, 1, fee, prices, dp);

        return ans;
    }
};