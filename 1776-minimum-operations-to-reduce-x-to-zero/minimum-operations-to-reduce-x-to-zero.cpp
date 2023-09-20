class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int target;
        vector<int> presum (n);
        presum[0] = nums[0];
        for(int i = 1; i < n; i++){
            presum[i] = presum[i-1] + nums[i];
        }
        if(presum[n-1] < x)
            return -1;
        target = presum[n-1] - x;
        int ans = -1;

        for(int i =0; i < n; i++){
            if(presum[i] == target){
                if(ans != -1)
                    ans = min(ans, n - (i+1));
                else
                    ans = n - (i+1);
            }
            else if(presum[i] > target){
                if(binary_search(presum.begin(), presum.end(), presum[i] - target)){
                    int pos;
                    pos = lower_bound(presum.begin(), presum.end(), presum[i] - target) - presum.begin();
                    if(ans != -1){
                        ans = min(ans, n - (i - pos));
                    }
                    else
                        ans = n - (i - pos);
                }
            }
        }

        return ans;
    }
};