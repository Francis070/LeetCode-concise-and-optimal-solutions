class Solution {
public:

    int dp[1003][1003];

    int rec(int i, int j, int n, int m, string &s, string &t, int & ans){
        // if(i >= n || j >= m){
        if(j >= m)
            return 1;
        if(i >= n)
            return 0;
            // return 1;
        // }

        if(dp[i][j] != -1)
            return dp[i][j];

        int get = 0;
        if(s[i] == t[j]){
            get = rec(i + 1, j + 1, n, m, s, t, ans) + rec(i + 1 , j, n, m, s,t, ans);
        }
        else{
            get = rec(i + 1 , j, n, m, s,t, ans);
        }

        return dp[i][j] = get;
    }

    int numDistinct(string s, string t) {
        int ans = 0;
        int n = s.size(), m =t.size();
        memset(dp, -1, sizeof(dp));
        ans = rec(0, 0, n, m, s, t, ans);

        // for(int i =0; i <= n; i++){
        //     for(int j = 0; j <= m; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return ans;
    }
};