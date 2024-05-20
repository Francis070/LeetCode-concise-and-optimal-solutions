class Solution {
public:

    void rec(int ind, int val, int n, int &ans, vector<int> & nums){
        if(ind >= n){
            ans += val;
            return;
        }

        rec(ind + 1, val ^ nums[ind], n, ans, nums);
        rec(ind + 1, val, n, ans, nums);
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        rec(0, 0, n, ans, nums);

        return ans;
    }
};