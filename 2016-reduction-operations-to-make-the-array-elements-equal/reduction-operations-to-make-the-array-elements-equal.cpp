class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end(), greater<int>());
        int cnt = 1, ans = 0;
        for(int i = 1; i< n; i++){
            if(nums[i] != nums[i-1]){
            //     cnt++;
            // }
            // else{
                ans += (i);
            }
        }

        return ans;
    }
};