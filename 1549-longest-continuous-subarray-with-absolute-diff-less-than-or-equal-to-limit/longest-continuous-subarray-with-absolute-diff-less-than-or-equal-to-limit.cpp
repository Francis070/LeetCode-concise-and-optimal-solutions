class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();

        map<int, int> m;

        int i =0, j = 0;
        int ans = 0;
        while(j < n){
            
            m[nums[j]]++;

            int fval = (m.begin()->first);
            int sval = prev(m.end())->first;

            while(i < j && (sval - fval > limit)){
                if(m[nums[i]] == 1){
                    m.erase(nums[i]);
                }
                else{
                    m[nums[i]]--;
                }

                fval = m.begin()->first;
                sval = prev(m.end())->first;
                i++;
            }

            ans = max(ans, (j - i + 1));

           j++; 
        }

        return ans;
    }
};