class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int n = nums.size();

        long long int cur = 0;
        for(int i : nums)
            cur ^= i;

        cur &= -cur;

        // int cnt = 0;
        // int val = cur;
        // while(val > 0){
        //     if(val & 1){
        //         break;
        //     }
        //     cnt++;
        //     val>>= 1;
        // }

        // int er = pow(2, cnt);
        // cout<<er<<endl;
        vector<int> ans = {0, 0};
        for(int i = 0; i < n; i++){
            // cout<<nums[i]<<" "<<(er & nums[i])<<endl;
            if((cur & nums[i]) == 0){
                ans[0] ^= nums[i];
            }   
            else{
                ans[1] ^= nums[i];
            }
        }

        return ans;
    }
};