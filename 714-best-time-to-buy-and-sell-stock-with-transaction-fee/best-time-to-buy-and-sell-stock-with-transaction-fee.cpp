class Solution {
public:

    int rec(int ind, int n, bool chk, int f, vector<int> &p, vector<vector<int>> & dp){
        if(ind >= n)
            return 0;
        if(dp[ind][chk] != -1)
            return dp[ind][chk];
            
        int ans = 0;
        if(chk){
            int a = (-1 * p[ind]) + rec(ind + 1, n, 0, f, p, dp);
            int b =  rec(ind + 1, n, 1, f, p, dp);

            ans = max(a, b);
        }
        else{
            int a = p[ind] +  rec(ind + 1, n, 1, f, p, dp) - f;
            int b = rec(ind + 1, n, 0, f, p, dp);
            ans = max(a, b);
        }

        return dp[ind][chk] = ans;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 5, vector<int>(2, -1));
        int ans = rec(0, n, 1, fee, prices, dp);

        return ans;
    }
};