class Solution {
public:

    int rec(int ind, int md, vector<int> &days, vector<int>& costs, vector<vector<int>> &dp){
        if(ind >= days.size())
            return 0;

        if(dp[ind][md] != -1)
            return dp[ind][md];

        int ans = INT_MAX;
        if(md >= days[ind]){
            ans = min(ans, rec(ind + 1, md, days, costs, dp));
        }
        int odp = costs[0] + rec(ind + 1, days[ind], days, costs, dp);
        int sdp = costs[1] + rec(ind + 1, days[ind] + 6, days, costs, dp);
        int tdp = costs[2] + rec(ind + 1, days[ind] + 29, days, costs, dp);

        ans = min(ans, min(odp, min(sdp, tdp)));

        return dp[ind][md] = ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();

        vector<vector<int >> dp(n + 2, vector<int>(400, -1));
        return rec(0, 0, days, costs, dp);
    }
};