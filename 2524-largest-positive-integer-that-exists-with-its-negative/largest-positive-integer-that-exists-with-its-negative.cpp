class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        for(int i =0; i < n; i++){
            if(nums[i] < 0){
                if(binary_search(begin(nums), end(nums), abs(nums[i])))
                    return abs(nums[i]);
            }
        }

        return -1;
    }
};