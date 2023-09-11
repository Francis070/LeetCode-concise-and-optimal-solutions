class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> um;
        int n = nums.size();
        int r = -1;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int sum2 = 0;
        for(int i = 0; i < n; i++)
            sum2 += i+1;
        
        vector<int> ans;
        for(int i =0; i < n; i++){
            um[nums[i]]++;
            if(um[nums[i]] == 2){
                r = nums[i];
                break;
            }
        }
        ans.push_back(r);
        sum -= r;
        ans.push_back(sum2 - sum);
        return ans;
    }
};