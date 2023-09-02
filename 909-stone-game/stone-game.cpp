class Solution {
public:

    int rec(int s, int e, vector<int> & piles, vector<vector<int>> &dp){
        if(s > e){
            return 0;
        }

        if(dp[s][e] != -1)
            return dp[s][e];

        int lf = piles[s] + max(rec(s + 2, e, piles, dp), rec(s + 1, e - 1, piles, dp));
        int rt = piles[e] + max(rec(s, e - 2, piles, dp), rec(s + 1, e - 1, piles, dp));

        return dp[s][e] = max(lf, rt);

    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(502, vector<int>(502, -1));
        int ans = rec(0, n-1, piles, dp);
        int sum = 0;
        for(int x : piles)
            sum += x;

        return (ans > (sum - ans));
    }
};