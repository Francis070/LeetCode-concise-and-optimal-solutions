class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long rs = nums[0];
        long long ans = 1;
        long long i = 1, j = 0;

        while(i < n){
            rs += nums[i];
            long long ch = nums[i];
            while((ch * (i - j + 1)) - rs > k){
                rs -= nums[j++];
            }

            ans = max(ans, i - j + 1);
            i++;
        }

        return ans;

    }
};