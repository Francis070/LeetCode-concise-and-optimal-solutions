class Solution {
public:
    bool isAnagram(string s, string t) {
        int ss = s.size(), ts = t.size();

        if(ss != ts) return false;

        unordered_map<char, int> um;
        for(char x : t){
            um[x]++;
        }

        for(int i = 0; i < ss; i++){
            if(um.find(s[i]) == um.end())
                return false;
            else{
                um[s[i]]--;
                if(um[s[i]] == 0)
                    um.erase(s[i]);
            }
        }

        return true;
    }
};