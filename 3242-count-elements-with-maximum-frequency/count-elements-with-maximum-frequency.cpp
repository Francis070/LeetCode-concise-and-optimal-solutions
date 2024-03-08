class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        sort(begin(nums), end(nums));
        unordered_map<int, int> freq;

        int n = nums.size();
        int cur_freq = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1]){
                cur_freq++;
            }
            else{
                freq[cur_freq]++;
                cur_freq = 1;
            }
        }
        freq[cur_freq]++;
        int ans = 0, mxf = INT_MIN;
        for(auto & x : freq){
            if(x.first > mxf){
                mxf = x.first;
                ans = x.first * x.second;
            }
        }

        return ans;
    }
};