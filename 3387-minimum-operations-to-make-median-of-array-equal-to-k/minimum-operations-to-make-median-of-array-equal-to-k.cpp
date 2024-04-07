#define ll long long

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        ll ans = 0;
        // if(n % 2 == 0){

        // }
        // else{
        int x = nums[n/2];
        if(x == k)
            return 0;
        else{
            if(x < k){
                int pos = lower_bound(begin(nums), end(nums), k) - begin(nums) - 1;
                for(int i = n/2; i <= pos; i++){
                    ans += abs(k - nums[i]);
                }
            }
            else{
                int pos = upper_bound(begin(nums), end(nums), k) - begin(nums);
                for(int i = pos; i <= n/2; i++){
                    ans += abs(k - nums[i]);
                }
            }
        }
        // }


        return ans;
    }
};