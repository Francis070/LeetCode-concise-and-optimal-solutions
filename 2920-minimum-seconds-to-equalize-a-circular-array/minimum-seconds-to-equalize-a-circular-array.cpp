class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> um;

        for(int i = 0; i < n; i ++)
            um[nums[i]].push_back(i);
        
        int ans = INT_MAX;
        for(auto & x : um){
            vector<int> temp = x.second;

            int cur = ((temp[0] + n - temp[temp.size() - 1] - 1) + 1)/ 2;

            for(int i = 1; i < temp.size(); i++){
                cur = max(cur, (temp[i] - temp[i -1]) / 2);
            }

            ans = min(ans, cur);
        }

        return ans;
    }
};