class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> v;

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i]){
                cnt++;
            }
            else{
                if(cnt > 0){
                    v.push_back(cnt);
                    cnt = 0;
                }
                v.push_back(0);
            }
        }
        if(cnt > 0)
            v.push_back(cnt);

        if(v.size() == 1 && v[0] != 0)
            return v[0] - 1;

        int ans = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i] == 0){
                if(i-1 >= 0 && i + 1 < v.size() && v[i-1] != 0 && v[i + 1] != 0){
                    ans = max(ans, v[i-1] + v[i+1]);
                }
            }
            else{
                ans = max(ans, v[i]);
            }
        }

        return ans;
    }
};