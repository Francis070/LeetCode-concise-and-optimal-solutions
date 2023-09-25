class Solution {
public:
    char findTheDifference(string s, string t) {
        int x = 0;

        for(char c : s){
            x ^= int(c);
        }
        for(char c : t){
            x ^= int(c);
        }

        return char(x);
    }
};