#define ll long long
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        vector<ll> pre_s(n, 0);
        pre_s[0] = nums[0];

        for(int i = 1; i < n; i++){pre_s[i] = nums[i] + pre_s[i-1];}
        ll ans = -1;
        for(int i = n-1; i >= 2; i--){
            if(nums[i] < pre_s[i-1]){
                ans = pre_s[i];
                break;
            }
        }

        return ans;
    }
};