class Solution {
public:
    int dp[102][204];
    int rec(int ind, vector<int> &piles, int n, int m){
        if(ind  >= n){
            return 0;
        }

        if(dp[ind][m] != -1)
            return dp[ind][m];

        int ans = INT_MIN;
        int tot = 0;
        for(int i = 0; i < 2 * m; i++){
            if(i + ind < n)
                tot += piles[i + ind];

            ans = max(ans, tot - rec(ind + i + 1, piles, n, max(m, i + 1)));
        }

        return dp[ind][m] = ans;

    }


    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += piles[i];
        }

        int ans = rec(0, piles, n, 1);

        return (sum + ans)/2;

    }
};