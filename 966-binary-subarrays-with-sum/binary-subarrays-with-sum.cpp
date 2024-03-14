class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> freq;

        vector<int> pref = nums;
        freq[pref[0]]++;
        for(int i = 1; i < n; i++){
            pref[i] += pref[i - 1];
            freq[pref[i]]++;
        }
        int ans = 0;
        for(auto & x : freq){
            int a = x.first;
            int b = goal + a;

            if(a <= b){
                if(a == b && a == goal){
                    ans += (x.second * (x.second + 1))/2;
                }
                else if(a == b && a != goal){
                    ans += (x.second * (x.second - 1))/2;
                }
                else if(a != b){
                    if(a == goal){
                        ans += x.second;
                    }

                    if(freq.find(b) != freq.end()){
                        ans += (x.second * freq[b]);
                    }
                }
            }
        }

        return ans;
    }
};