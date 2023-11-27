class Solution {
public:

    vector<vector<int>> dirs = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};

    int dp[5003][11];
    int mod = 1e9 + 7;

    int rec(int st, int len){
        if(len == 1){
            return 1;
        }

        if(dp[len][st] != -1){
            return dp[len][st];
        }

        vector<int> cur = dirs[st];
        int val = 0;
        for(int i = 0; i < cur.size(); i++){
            val = (val + rec(cur[i], len - 1))%mod;
        }

        return dp[len][st] = val;
    }

    int knightDialer(int n) {
        memset(dp, -1, sizeof(dp));

        int ans = 0;

        for(int i = 0; i < 10; i++){
            ans = (ans + rec(i, n))%mod;
        }

        return ans;
    }
};