class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size();
        unordered_map<char, int> um;
        for(int i = 0; i < n; i++){
            um[s[i]]++;
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(um[t[i]] > 0){
                cnt++;
                um[t[i]]--;
            }
        }

        return n - cnt;
    }
};