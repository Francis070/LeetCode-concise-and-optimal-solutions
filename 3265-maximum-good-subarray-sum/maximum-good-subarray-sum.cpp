#define ll long long

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        ll ans = LLONG_MIN;

        unordered_map<int, vector<int>> um;
        vector<ll> pref(n, 0);

        for(int i = 0; i < n; i++){
            if(i == 0)
                pref[i] = nums[i];
            else
                pref[i] = pref[i-1] + nums[i];
            um[nums[i]].push_back(i);
        }

        for(int i = 0;  i < n; i++){
            int t1 = nums[i] + k;
            int t2 = nums[i] - k;

            for(int x : um[t1]){
                if(x > i) ans = max(ans, pref[x] - pref[i] + nums[i]);
            }
            for(int x : um[t2]){
                if(x > i) ans = max(ans, pref[x] - pref[i] + nums[i]);
            }
        }
        if(ans == LLONG_MIN)
            return 0;
        return ans;
    }
};