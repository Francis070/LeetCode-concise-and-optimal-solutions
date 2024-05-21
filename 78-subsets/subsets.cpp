class Solution {
public:

    void rec(int ind, int n, vector<int>& vt, vector<vector<int>> & ans, vector<int> & nums){
        if(ind >= n){
            ans.push_back(vt);
            return;
        }
        vt.push_back(nums[ind]);
        rec(ind + 1, n, vt, ans, nums);
        vt.pop_back();
        rec(ind + 1, n, vt, ans, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
       int n = nums.size();

       vector<vector<int>> v;
       vector<int> er;
        rec(0, n, er, v, nums);

        return v;
    }
};