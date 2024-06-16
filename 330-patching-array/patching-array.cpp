#define ll long long int 
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        // this need to be repeated as this is written using help from Solutions

        ll miss = 1;
        int ans = 0;
        int i = 0 ;
        int m = nums.size();
        while(miss <= n){
            if(i < m && nums[i] <= miss){
                miss += nums[i];
                i++;
            }
            else{
                miss += miss;
                ans++;
            }
        }

        return ans;
    }
};