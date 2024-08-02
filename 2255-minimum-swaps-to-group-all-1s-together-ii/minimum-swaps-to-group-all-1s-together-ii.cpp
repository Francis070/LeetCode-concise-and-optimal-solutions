class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int tot = 0;
        for(int i = 0; i < n; i++){
            tot += nums[i];
        }

        vector<int> v(begin(nums), end(nums));
        for(int i = 0; i < n; i++) v.push_back(nums[i]);

        int st = 0, en = 0;
        int cc = 0;
        int ans = INT_MAX;
        while(en < v.size()){
            cc += v[en];

            if((en - st + 1) > tot){
                cc -= v[st];
                st++;
            }

            if((en - st + 1) == tot){
                ans = min(ans, tot - cc);
            }

            en ++;
        }

        return ans;
    }
};