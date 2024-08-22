class Solution {
public:

    long long dp[503][503];

    long long rec(int row, int p2, int p1, vector<vector<pair<long long, int>>> &vp){
        if(row >= vp.size())
            return (-1e18);

        if(dp[row][p1 + 1] != -1)
            return dp[row][p1 + 1];


        //not in the same row 
        long long cur = rec(row + 1, p2, p1, vp);

        for(int i = 0; i <3; i++){
            if(vp[row][i].second != p1 && vp[row][i].second != p2){
                if(p1 != -1){
                    cur = max(cur, vp[row][i].first);
                }
                else {
                    cur = max(cur, vp[row][i].first + rec(row + 1, p2, vp[row][i].second, vp));
                }
            }
        }

        return dp[row][p1 + 1] = cur;
    }

    long long maximumValueSum(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<pair<long long, int>>> vp(n, vector<pair<long long, int>>(m));

        for(int i= 0; i < n; i++){
            for(int j = 0; j < m; j++){
                vp[i][j] = {board[i][j], j};
            }
            sort(vp[i].rbegin(), vp[i].rend());
        }

        sort(vp.rbegin(), vp.rend());

        // vector<vector<long long>> dp(503, vector<long long>(503))
        long long ans = -1e18;
        for(int i = 0; i < 3; i++){
            memset(dp, -1, sizeof(dp));

            ans = max(ans, vp[0][i].first + rec(1, vp[0][i].second, -1, vp));
        }

        return ans;
    }
};