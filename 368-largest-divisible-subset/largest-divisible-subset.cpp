class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n + 1, 1);

        for(int i = 0; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                if(nums[i] % nums[j] == 0){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int mx = *max_element(dp.begin(), dp.end());
        int pos = -1;
        for(int i = 0; i < n; i++){
            if(dp[i] == mx){
                pos = i;
                break;
            }
        }

        int prev = nums[pos];
        vector<int> ans;
        ans.push_back(prev);
        mx--;
        for(int i = pos - 1; i >= 0; i--){
            if(prev % nums[i] == 0 && dp[i] == mx){
                ans.push_back(nums[i]);
                prev = nums[i];
                mx--;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};