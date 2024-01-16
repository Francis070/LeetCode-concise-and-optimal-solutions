class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();

        vector<int> v(1e4 + 5, 0);
        for(int i = 0; i < n; i++)
            v[nums[i]]++;
        
        vector<int> dp(1e4 + 5, 0);
        dp[1] = v[1];
        dp[0] = 0;
        for(int i = 2; i <= 1e4 + 3; i++){
            dp[i] = max(v[i] * i + dp[i-2], dp[i-1]);
        }

        // for(int i = 0; i < 5; i++)
        //     cout<<dp[i]<<" ";
        int mx = INT_MIN;
        for(int i = 0; i < dp.size(); i++){
            mx = max(mx, dp[i]);
        }

        return mx;
    }
};