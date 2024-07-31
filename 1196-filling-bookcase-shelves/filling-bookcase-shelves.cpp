class Solution {
public:

    int rec(int ind, int wd, int ht, int n, int sw, vector<vector<int>>& books,  vector<vector<int>> & dp){
        if(ind >= n){
            return ht;
        }

        if(dp[ind][wd] != -1)
            return dp[ind][wd];
        
        int cur = INT_MAX;
        if(books[ind][0] <= wd){
            cur = rec(ind + 1, wd - books[ind][0], max(ht, books[ind][1]), n, sw, books, dp);
        }

        cur = min(cur, ht + rec(ind + 1 , sw - books[ind][0], books[ind][1], n, sw, books, dp));

        return dp[ind][wd] = cur;
    }

    int minHeightShelves(vector<vector<int>>& books, int sw) {
        int n = books.size();

        vector<vector<int>> dp(1003, vector<int>(1003, -1));

        int ans = rec(0, sw, 0, n, sw, books, dp);

        return ans;
    }
};