class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0, n = nums.size();

        for(int i = 0; i < n; i++){
            if(i >= 2){
                int dif = nums[i] - nums[i-1];
                int cnt = 1, j = i;
                while(j > 0 && nums[j] - nums[j-1] == dif){
                    j--; cnt++;
                }
                ans += max(0, cnt - 2);
            }
        }

        return ans;
    }
};