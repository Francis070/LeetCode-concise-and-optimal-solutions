class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans =0;
        unordered_map<int, int> um;
        for(int i =0; i < n; i++){
            if(nums[i] == 0)
                sum--;
            else
                sum++;


            if(sum == 0)
                ans = max(ans, i + 1);
            else{
                if(um.find(sum) != um.end()){
                    ans = max(ans, i - um[sum]);
                }
                else{
                    um[sum] = i;
                }
            }
        }

        return ans;
    }
};