class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();

        long long mul = 1<<k;

        long long ans = 0;
        vector<long long> pre(n), suf(n);

        pre[0] = nums[0];
        suf[n-1] = nums[n-1];

        for(int i = 1; i< n; i++){
            pre[i] = pre[i-1] | nums[i];
        }
        for(int i = n-2; i >= 0; i--){
            suf[i] = suf[i + 1] | nums[i];
        }
        ans = max(pre[0] * mul, suf[n-1] * mul);
        for(int i = 0; i < n; i++){
            if(i == 0){
                long long t = nums[i] * mul;
                long long tt = 0;
                if(i + 1 < n)
                    tt = suf[i + 1];
                ans = max(ans, t | tt);
            }
            else if( i == n-1){
                long long t = nums[i] * mul;
                long long tt = 0;
                if(i - 1 >= 0)
                    tt = pre[i - 1];
                ans = max(ans, t | tt);
            }
            else{
                long long t = nums[i] * mul;
                long long tp = pre[i-1], ts = suf[i + 1];
                
                ans = max(ans, t | tp | ts);
            }
        }

        return ans;
    }
};