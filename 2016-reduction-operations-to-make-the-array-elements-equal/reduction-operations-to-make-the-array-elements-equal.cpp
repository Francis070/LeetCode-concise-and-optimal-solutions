class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end(), greater<int>());
        int ans = 0;
        for(int i = 1; i< n; i++){
            if(nums[i] != nums[i-1]){
                ans += (i);
            }
        }

        return ans;
    }
};