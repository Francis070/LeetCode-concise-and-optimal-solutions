class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        int pos = -1, val = INT_MAX;
        for(int i = 0; i < n; i++){
            if(abs(nums[i]) < val){
                pos = i;
                val = abs(nums[i]);
            }
        }
        vector<int> res;
        int left = pos, right = pos + 1;
        while(left >= 0 && right < n){
            if(pow(nums[left], 2) <= pow(nums[right], 2)){
                res.push_back(pow(nums[left], 2));
                left--;
            }
            else{
                res.push_back(pow(nums[right], 2));
                right++;
            }
        }

        if(left >= 0){
            for(int i = left; i>= 0; i--){
                res.push_back(pow(nums[i], 2));
            }
        }
        if(right < n){
            for(int i = right; i < n; i++){
                res.push_back(pow(nums[i], 2));
            }
        }

        return res;
    }
};