class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> um;
        int sum = 0, ans= 0;
        um[0]= 1;
        for(int i = 0 ; i< n; i++){
            sum += nums[i];
            int f = sum - k;

            if(um.find(f) != um.end()){
                ans += um[f];
            }
            um[sum]++;
        }
        return ans;
    }
};