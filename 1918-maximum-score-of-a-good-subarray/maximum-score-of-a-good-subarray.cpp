class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        int mn = nums[k];
        int i = k;
        int j = k;
        int ans = mn;

        while(i > 0 || j < n-1){
            if( (i > 0 ? nums[i- 1]: 0) < (j < n-1 ? nums[j + 1] : 0) ){
                j++;
                mn = min(mn, nums[j]);
                
            }
            else{
                i--;
                mn = min(mn, nums[i]);
                
            }
            ans = max(ans, mn * (j - i + 1));
        }

        return ans;
    }
};