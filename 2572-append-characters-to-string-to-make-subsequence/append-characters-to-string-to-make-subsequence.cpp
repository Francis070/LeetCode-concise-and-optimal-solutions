class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size();

        int i = 0, j = 0;

        for(int i =0; i < n; i++){
            if(j < t.size() && s[i] == t[j]){
                j++;
            }
        }

        int ans = t.size() - j;
        return ans;
    }
};