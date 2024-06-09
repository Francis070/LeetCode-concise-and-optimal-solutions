class Solution {
public:
    int dp[504][504][27];
    int rec(int n, int ind, int le, int k, vector<int> & nums
    // vector<vector<vector<int>>> &dp
    // map<vector<int>, int> &dp
    ){
        // if(k < 0 || ind >= n){
        //     return 0;
        // }

        if(ind >= n){
            return 0;
        }
        // consider

        // if(le != -1 && dp[ind][le][k] != -1){
        //     return dp[ind][le][k];
        // }

        // vector<int> ee;
        // ee.push_back(ind);
        // ee.push_back(le);
        // ee.push_back(k);
        // if(dp.find(ee) != dp.end()){

        //     return dp[ee];
        // }

        if(dp[ind + 1][le + 1][k+ 1] != -1)
            return dp[ind + 1][le + 1][k+ 1];

        // int con = 0, dc = 0;
        int ans = -1;

        if(le > -1){
            if(nums[le] != nums[ind]){
                if(k - 1 >= 0){
                    // con = 1 + rec(n, ind + 1, ind, k-1, nums, dp);
                    // dc = rec(n, ind + 1, le, k, nums, dp);
                    ans = max(ans, 1 + rec(n, ind + 1, ind, k-1, nums));
                    // ans = max(ans, rec(n, ind + 1, le, k, nums, dp));
                }   
                // else{
                    // dc = rec(n, ind + 1, le, k, nums, dp);
                ans = max(ans, rec(n, ind + 1, le, k, nums));
                // }
            }
            else{
                // con = 1 + rec(n, ind + 1, ind, k, nums, dp);
                // dc = rec(n, ind + 1, le, k, nums, dp);
                ans = max(ans, 1 + rec(n, ind + 1, ind, k, nums));
                // ans = max(ans, rec(n, ind + 1, le, k, nums, dp));
            }
        }
        else{
            // con = 1 + rec(n, ind + 1, ind, k, nums, dp);
            // dc = rec(n, ind + 1, le, k, nums, dp);
            ans = max(ans, 1 + rec(n, ind + 1, ind, k, nums));
            ans = max(ans, rec(n, ind + 1, le, k, nums));
        }

        // dc = rec(n, ind + 1, le, k, nums, dp);

        // if(le != -1){
        //     dp[ind][le][k] = max(con, dc);
        // }
        // return dp[ee] = ans;
        // return max(con, dc);
        return dp[ind + 1][le + 1][k+ 1] = ans;

    }

    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        // vector<vector<vector<int>>> dp(504, vector<vector<int>>(504, vector<int>(26, -1)));
        // map<vector<int>, int> dp;
        int ans = rec(n , 0, -1, k, nums);
        // int ans = 0;
        return ans;
    }
};