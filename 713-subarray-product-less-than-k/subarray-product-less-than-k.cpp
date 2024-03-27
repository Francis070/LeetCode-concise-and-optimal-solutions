#define ll long long

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        int i =0, j = 0;
        ll cp = 1;
        int ans = 0;
        while(i < n){
            cp *= nums[i];
            if(cp >= k){
                int t = i - j;
                ans +=  (t* (t + 1))/2;
                while(cp >= k && j <= i){
                    cp /= nums[j];
                    j++;
                }
                t = i-j;
                ans -= (t* (t + 1))/2;
            }

            i++;
        }   

        int t = i - j;
        ans +=  (t* (t + 1))/2;
        return ans;
    }
};