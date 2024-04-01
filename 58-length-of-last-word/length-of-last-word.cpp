class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(begin(s), end(s));

        bool chk = false;
        int i = 0;
        int ans = 0;
        while(i < s.size()){
            if(s[i] == ' '){
                if(chk)
                    break;
            }
            else{
                ans++;
                chk = true;
            }
            i++;
        }
        return ans;
    }
};