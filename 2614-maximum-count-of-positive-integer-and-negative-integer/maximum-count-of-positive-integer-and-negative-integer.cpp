class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int s = lower_bound(begin(nums), end(nums), 0) - begin(nums);
        int e = upper_bound(begin(nums), end(nums), 0) - begin(nums);

        return (max(s, n - e));
    }
};