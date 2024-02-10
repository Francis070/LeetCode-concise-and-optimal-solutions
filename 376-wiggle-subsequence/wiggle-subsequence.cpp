class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(2, vector<int>(n, 1));
        // [0] -> 1 - 2
        // [1] -> 2 - 1
        int ans = 1;
        for(int i = 1; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                if(nums[i] < nums[j]){
                    dp[1][i] = max(dp[0][j] + 1, dp[1][i]); 
                }
                else if(nums[i] > nums[j]){
                    dp[0][i] = max(dp[1][j] + 1, dp[0][i]);
                }
                
            }
            ans = max(ans, max(dp[0][i], dp[1][i]));
        }

        return ans;
    }
};