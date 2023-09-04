class Solution {
public:
    int dp[400][400];
    int rec(int ind, int tillDay, int n, vector<int>& days, vector<int>& costs){
        if(ind >= n)
            return 0;
        if(dp[ind][tillDay] != -1)
            return dp[ind][tillDay];
        int ans = INT_MAX;
        if(tillDay < days[ind]){
            for(int i = 0; i < 3; i++){
                int further = days[ind];
                if(i == 1)
                    further += 6;
                else if(i == 2)
                    further += 29;
                
                ans = min(ans, costs[i] + rec(ind + 1, further, n, days, costs));
            }
        }
        else{
            ans = min(ans, rec(ind + 1, tillDay, n, days, costs));
        }

        return dp[ind][tillDay] = ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        memset(dp, -1, sizeof(dp));
        int ans = rec(0, 0, n, days, costs);

        return ans;
    }
};