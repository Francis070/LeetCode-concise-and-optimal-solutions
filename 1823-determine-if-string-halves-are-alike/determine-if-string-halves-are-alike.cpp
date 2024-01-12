class Solution {
public:
    bool chk_vowel(char c){
        unordered_map<char, int> um;
        um['a'] = 1; um['A'] = 1; um['e'] = 1; um['E'] = 1; um['i'] = 1; um['I'] = 1;
        um['o'] = 1; um['O'] = 1; um['u'] = 1; um['U'] = 1;

        if(um[c])
            return true;
        return false;
    }

    bool halvesAreAlike(string s) {
        int n = s.size();
        int first_half = 0, second_half = 0;
        for(int i =0; i< n/2; i++)
            if(chk_vowel(s[i]))
                first_half++;
        
        for(int i = n/2; i< n; i++)
            if(chk_vowel(s[i]))
                second_half++;

        return first_half == second_half;
    }
};