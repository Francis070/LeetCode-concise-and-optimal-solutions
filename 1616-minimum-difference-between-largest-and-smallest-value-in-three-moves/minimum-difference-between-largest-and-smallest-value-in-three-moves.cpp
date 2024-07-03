class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int mn = INT_MAX;

        if(n >= 5){
            // mn = min(mn, nums[n-4]- nums[0]);
            // mn = min(mn, nums.back() - nums[3]);

            for(int i = 0; i <= 3; i++){
                mn = min(nums[n - 4 + i] - nums[i], mn);
            }
        }
        else{
            mn = 0;
        }

        

        return mn;
    }
};