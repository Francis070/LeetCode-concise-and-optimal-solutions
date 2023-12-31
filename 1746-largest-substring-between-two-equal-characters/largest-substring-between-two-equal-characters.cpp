class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1, n = s.size();
        unordered_map<char, int> um;
        for(int i = 0; i < n; i++){
            if(um.find(s[i]) == um.end()){
                um[s[i]] = i;
            }
            else{
                ans = max(ans, i - um[s[i]] - 1);
            }
        }

        return ans;
    }
};