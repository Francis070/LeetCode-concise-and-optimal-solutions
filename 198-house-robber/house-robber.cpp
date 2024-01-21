class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        // int val, p = -1, pp = -1;
        // pp = nums[0];
        // p = (n > 1) ? max(nums[1], nums[0]) : -1;

        // val = max(p, pp);

        // for(int i = 2; i < n; i++){
        //     pp += nums[i];
        //     val = max(p, pp);
        //     swap(pp, p);
        // }

        // return val;

        dp[0] = nums[0];
        if(n > 1)
            dp[1] = max(nums[1], nums[0]);

        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-1], nums[i] + dp[i - 2]);
        }
        return dp[n-1];
    }
};