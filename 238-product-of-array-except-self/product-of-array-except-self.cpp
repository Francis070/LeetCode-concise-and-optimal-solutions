class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        int zc = 0;
        for(int i : nums)
            if(i == 0)
                zc++;
        
        vector<int> ans(n, 0);

        if(zc > 1)
            return ans;
        else{
            long long oth = 1;
            for(int i : nums)
                if(i != 0)
                    oth *= i;

            for(int i = 0; i < n; i++){
                if(nums[i] == 0)
                    ans[i] = oth;
                else if(zc == 1){
                    ans[i] = 0;
                }
                else{
                    ans[i] = (oth)/nums[i];
                }
                    
            }
        }

        return ans;
    }
};