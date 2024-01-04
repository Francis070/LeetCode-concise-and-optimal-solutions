class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> um;
        for(int i = 0; i < n; i++)
            um[nums[i]]++;
        int ans = 0;
        for(auto &x : um){
            if(x.second % 3 == 0){
                ans += (x.second / 3);
            }
            else{
                if(x.second % 3 != 0 && x.second >= 3){
                    ans += (x.second/3) + 1;
                }
                else if(x.second % 2 == 0 && x.second >= 2){
                    ans += (x.second/2); 
                }
                else{
                    return -1;
                }
            }
        }

        return ans;
    }
};