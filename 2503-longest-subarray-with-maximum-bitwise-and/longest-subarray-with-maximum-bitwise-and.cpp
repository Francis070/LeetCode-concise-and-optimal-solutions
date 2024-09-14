class Solution {
public:
    int len(int x){
        int res = 0;
        while(x){
            x >>= 1;
            res++;
        }
        return res;
    }
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        int mx = 0;
        for(auto & x : nums)
            mx = max(x, mx);
        // for(int i = 0; i < n; i++){
        //     v[i] = len(nums[i]);
        //     mx = max(mx, v[i]);
        // }
        int ans = 1;
        
        for(int i = 0; i < n; i++){
            if(nums[i] == mx){
                int j = i;
                int cur = 0;
                while(j< n && nums[j] == mx){
                    cur++;
                    ans = max(ans, cur);
                    j++;
                }
                i = j;
            }
        }

        return ans;
    }
};