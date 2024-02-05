class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        unordered_map<char, int> um;
        for(char c : s){
            um[c]++;
        }

        for(int i = 0; i < n; i++){
            if(um[s[i]] == 1)
                return i;
        }
        return -1;
    }
};