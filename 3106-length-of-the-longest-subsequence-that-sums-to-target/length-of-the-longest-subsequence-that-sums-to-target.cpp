class Solution {
public:
    int dp[1001][1001];
    int rec(int ind, int target, vector<int> & nums){
        if(target == 0)
            return 0;
        if(ind >= nums.size() || target < 0){
            return INT_MIN;
        }

        if(dp[ind][target] != -1)
            return dp[ind][target];

        int x = 1 + rec(ind + 1, target - nums[ind], nums);

        int y = rec(ind + 1, target, nums);

        return dp[ind][target] = max(x, y);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        int ans = rec(0, target, nums);

        if(ans <= 0)
            return -1;
        return ans;

    }
};