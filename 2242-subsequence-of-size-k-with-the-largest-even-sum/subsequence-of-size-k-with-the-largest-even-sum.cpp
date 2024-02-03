#define ll long long

class Solution {
public:
    long long largestEvenSum(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        ll ans = 0;
        for(int i = 0; i < k; i++){
            ans += nums[i];
        }

        if(ans % 2 == 0)
            return ans;

        int sm_o = INT_MAX, sm_e = INT_MAX, lr_o = INT_MIN, lr_e = INT_MIN;

        for(int i = k-1; i >= 0; i--){
            if(nums[i]%2 == 0){
                sm_e = min(sm_e, nums[i]);
            }
            else{
                sm_o = min(sm_o, nums[i]);
            }
        }

        for(int i = k; i < n; i++){
            if(nums[i]%2 == 0){
                lr_e = max(lr_e, nums[i]);
            }
            else{
                lr_o = max(lr_o, nums[i]);
            }
        }
        // cout<<sm_o<<" "<<sm_e<<" "<<lr_o<<" "<<lr_e<<endl;
        ll va = INT_MIN, vb = INT_MIN;
        if(sm_o != INT_MAX && lr_e != INT_MIN){
            va  = ans - sm_o + lr_e;
        }
        
        if(sm_e != INT_MAX && lr_o != INT_MIN){
            vb = ans - sm_e + lr_o;
        }
        // cout<<va<<" "<<vb;
        // ans = 
        ans = max(va, vb);
        // if(va % 2 == 0 && va != INT_MIN)
        //     ans = va;
        // if(vb % 2 == 0 && vb != INT_MIN)
        //     ans = max(ans, vb);

        if(ans % 2 != 0 || ans == INT_MIN)
            return -1;
        return ans;
    }
};