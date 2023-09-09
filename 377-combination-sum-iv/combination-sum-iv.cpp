class Solution {
public:

    int rec(int t, vector<int>& nums, vector<int> &dp){

        if(dp[t] != -1)
            return dp[t];
        // if(t == 0)
        //     return 1;
        
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= t)
                res += rec(t - nums[i], nums, dp);
        }

        return dp[t] = res;
    }

    int combinationSum4(vector<int>& nums, int target) {
        // int n = nums.size();
        vector<int> dp(target + 5, -1);
        dp[0] = 1;

        int ans = rec(target, nums, dp);

        return ans;
    }
};