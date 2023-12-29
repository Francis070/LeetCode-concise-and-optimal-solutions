class Solution {
public:
    int dp[302][1001][11];

    long long rec(int ind, int n, int mx, int d, vector<int> &jd){
        if(ind == n){
            if(d == 0)
                return mx;
            else
                return INT_MAX;
        }

        if(d < 0)
            return INT_MAX;

        if(dp[ind][mx][d] != -1)
            return dp[ind][mx][d];

        long long ans = min(rec(ind + 1, n, max(mx, jd[ind]), d, jd), 
                        mx + rec(ind + 1, n, jd[ind], d - 1, jd));
        

        return dp[ind][mx][d] = ans;
    }
    int minDifficulty(vector<int>& jd, int d) {
        memset(dp, -1, sizeof(dp));
        int n = jd.size();
        // if(d == 1){
        //     int sum  = 0;
        //     for(int x : jd)
        //         sum += x;
        //     return sum;
        // }

        if(n < d)
            return -1;

        
        long long ans = rec(1, n, jd[0], d-1 , jd);
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};