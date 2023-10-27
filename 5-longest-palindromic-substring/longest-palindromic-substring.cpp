class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ans = 0;
        string ans_str;
        for(int i = 0; i< n; i++){
            string temp = "";
            //for odd length
            int x = i-1, y = i +1;
            int cur = 1;
            while(x >= 0 && y < n && s[x] == s[y]){
                x--; y++;
                cur+=2;

            }
            if(cur > ans){
                ans = cur;
                ans_str = s.substr(++x, y - x);
            }

            //for even length

            cur = 0;
            x = i-1; y = i;
            while(x >= 0 && y < n && s[x] == s[y]){
                x--; y++;
                cur+=2;
            }

            if(cur > ans){
                ans = cur;
                ans_str = s.substr(++x, y - x);
            }
        }

        return ans_str;
    }
};