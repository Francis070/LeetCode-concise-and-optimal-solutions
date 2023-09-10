class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        
        set<long long> st;
        long long ans = INT_MAX;
        for(int i = x; i < n && ans > 0; i++){
            st.insert(nums[i - x]);
            // auto lb = lower_bound(st.begin(), st.end(), nums[i]);
            auto lb = st.lower_bound(nums[i]);
            if(lb == end(st)){
                lb--;
                ans = min(ans, abs(nums[i] - *lb));
            }else{
                ans = min(ans, abs(nums[i] - *lb));
                if(lb != begin(st))
                    lb--;
                ans = min(ans, abs(nums[i] - *lb));
            }
        }
        
        return ans;
    }
};