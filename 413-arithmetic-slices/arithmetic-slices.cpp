class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0, n = nums.size();
        if(n < 3)
            return ans;

        int prev_diff = nums[1] - nums[0], diff;
        int cnt = 0;
        for(int i = 2; i < n; i++){
            diff = nums[i] - nums[i-1];
            if(prev_diff == diff)
                cnt++;
            else
                cnt = 0;

            prev_diff = diff;
            ans += cnt;
        }
        
        return ans;
    }
};