class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp, up;
        int n = s.size();
        for(int i =0; i < n; i++){
            if(mp.find(s[i]) != mp.end() && mp[s[i]] != t[i])
                return false;
            else if(mp.find(s[i]) == mp.end())
                mp[s[i]] = t[i];
        }

        for(int i =0; i < n; i++){
            if(up.find(t[i]) != up.end() && up[t[i]] != s[i])
                return false;
            else if(up.find(t[i]) == up.end())
                up[t[i]] = s[i];
        }

        return true;
    }
};