class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        long long eve = (nums[0]%2) ? nums[0] - x : nums[0];
        long long odd = (nums[0]%2) ? nums[0] : nums[0] - x;

        for(int i = 1; i < n; i++){
            if(nums[i] % 2){
                odd = nums[i] + max(odd, eve - x);
            }
            else{
                eve = nums[i] + max(eve, odd - x);
            }
        }
        
        return max(eve, odd);
        
    }
};