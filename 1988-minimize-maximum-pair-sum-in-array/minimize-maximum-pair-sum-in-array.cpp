class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // int mn = *min_element(nums.begin(), nums.end());
        // int mx = *max_element(nums.begin(), nums.end());
        int n = nums.size(), ans = INT_MIN;
        sort(nums.begin(), nums.end());
        int i = 0, j = n-1;
        while(i < j){
            ans = max(ans, nums[i] + nums[j]);
            i++; j--;
        }

        return ans; 
    }
};