class Solution {
public:

    int rec(int ind, int prev, vector<int>& nums, vector<vector<int>> &dp){
        if(ind >= nums.size())
            return 0;

        if(prev != -1 && dp[ind][prev] != -1)
            return dp[ind][prev];
        int ans = 0;
        if(prev == -1 || nums[ind] > nums[prev]){
            ans = max(ans, 1 + rec(ind + 1, ind, nums, dp));
        }

        ans = max(ans, rec(ind + 1, prev, nums, dp));

        if(prev == -1)
            return ans;
        else{
            return dp[ind][prev] = ans;
        }

        // return dp[ind][prev] = ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        int len = rec(0, -1, nums, dp);

        return len;
    }
};