class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> v;

        for(int i =0; i < n; i++){
            int ele = nums[i];

            int pos = lower_bound(v.begin(), v.end(), ele) - v.begin();
            if(pos == v.size()) v.push_back(ele);
            else{
                v[pos] = ele;
            }

           
        }
         return v.size();
    }
};