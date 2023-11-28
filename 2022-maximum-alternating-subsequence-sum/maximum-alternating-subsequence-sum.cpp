class Solution {
public:

    long long dp[100005][3];

    long long rec(int ind, int n, int sign, vector<int>& nums){
        if(ind >= n){
            return 0;
        }

        if(dp[ind][sign] != -1)
            return dp[ind][sign];


        long long ans = INT_MIN, val = nums[ind];
        if(sign == 0)
            val = (nums[ind])*(-1);

        ans = max(ans, val + rec(ind + 1, n, (sign + 1)%2, nums));
        ans = max(ans, rec(ind + 1, n, sign, nums));

        return dp[ind][sign] = ans;
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        long long ans = rec(0, n, 1, nums);

        return ans;
    }
};