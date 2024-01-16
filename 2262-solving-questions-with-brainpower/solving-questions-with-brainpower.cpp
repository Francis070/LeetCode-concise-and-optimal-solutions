class Solution {
public:

    long long rec(int ind, int n, vector<vector<int>> & qns, vector<long long> &dp ){
        if(ind >= n){
            return 0;
        }
        if(dp[ind] != -1)
            return dp[ind];
        //choose the task
        long long pts = 0;
        pts = max(qns[ind][0] + rec(ind + qns[ind][1] + 1, n, qns, dp), rec(ind + 1, n, qns, dp));

        return dp[ind] = pts;


    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n= questions.size();

        vector<long long> dp(n +1, -1);

        return rec(0, n, questions, dp);
    }
};