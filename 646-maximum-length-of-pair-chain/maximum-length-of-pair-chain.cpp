class Solution {
public:

    static bool comp(vector<int> &a, vector<int> & b){
        if(a[0] == b[0])
            return a[1] < b[1];

        return a[0] < b[0];
    }

    int rec(int ind, int prev, int n, vector<vector<int>> & pairs, vector<vector<int>> & dp){
        if(ind >= n)
            return 0;
        
        if(prev != -1 && dp[ind][prev] != -1)
            return dp[ind][prev];

        int ans = 0;

        if(prev == -1){
            ans = max(ans, 1 + rec(ind + 1, ind,n, pairs, dp));
        }
        else if(pairs[ind][0] > pairs[prev][1]){
            ans = max(ans, 1 + rec(ind + 1, ind,n, pairs, dp));
        }

        ans = max(ans, rec(ind + 1, prev,n, pairs, dp));

        if(prev != -1)
            return dp[ind][prev] = ans;
        return ans;
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp);

        int n = pairs.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        int ans = rec(0, -1, n, pairs, dp);

        return ans;  
    }
};