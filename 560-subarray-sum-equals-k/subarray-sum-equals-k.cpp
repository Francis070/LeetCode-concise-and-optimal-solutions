class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> pref(n, 0);
        pref[0] = nums[0];
        for(int i = 1; i < n; i++)
            pref[i] = pref[i-1] + nums[i];
        
        int ans = 0;
        for(int i =0; i< n; i++){
            if(pref[i] == k)
                ans ++;
            for(int j = 0; j < i; j++){
                if(pref[i] - pref[j] == k)
                    ans++;
            }
        }

        return ans;
    }
};