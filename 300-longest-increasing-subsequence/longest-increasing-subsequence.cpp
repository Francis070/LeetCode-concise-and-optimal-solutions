class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> res;

        for(int i =0 ; i < n; i++){
            int x = nums[i];

            int pos = lower_bound(res.begin(), res.end(), x) - res.begin();
            if(pos == res.size()){
                res.push_back(x);
            }
            else{
                res[pos] = x;
            }
        }
        
        return res.size();
    }
};