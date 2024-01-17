class Solution {
public:

    int rec(int ind, int prev, int n, vector<int> & nums, vector<vector<int>> &dp){
        if(ind >= n)
            return 0;
        if(prev != -1 && dp[ind][prev] != -1)
            return dp[ind][prev];
        int ans = 0;
        if(prev == -1){
            ans = max(ans, 1 + rec(ind + 1, ind, n, nums, dp));
        }
        else if(nums[ind] > nums[prev]){
            ans = max(ans,  1 + rec(ind + 1, ind, n, nums,dp));
        }
        ans = max(ans,  rec(ind + 1, prev, n, nums, dp));
        if(prev != -1)
            return dp[ind][prev] = ans;
        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int ans = rec(0, -1, n, nums, dp);
        return ans;
    }
};