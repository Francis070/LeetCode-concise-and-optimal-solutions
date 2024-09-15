class Solution {
public:
    //need to revisit this approach.
    int findTheLongestSubstring(string s) {
        int n = s.size();

        unordered_map<char, int> um;
        um['a'] = 1;
        um['e'] = 2;
        um['i'] = 4;
        um['o'] = 8;
        um['u'] = 16;

        vector<int> v(n, 0);
        for(int i = 0; i < n; i++){
            v[i] = um[s[i]];
        }

        map<int, vector<int>> mp;
        int cx = 0;
        for(int i = 0; i <n; i++){
            cx ^=v[i];
            mp[cx].push_back(i);
        }
        int ans = 0;
        for(auto & x : mp){
            if(x.first != 0){
                ans = max(ans, x.second.back() - x.second[0]);
            }
            else{
                ans = max(ans, x.second.back() + 1);
            }
            
        }

        return ans;
    }
};