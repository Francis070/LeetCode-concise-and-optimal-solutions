class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> um;
        for(char c : s){
            um[c]++;
        }
        int ans = 0;
        int chk = 0;
        for(auto & c : um){
            if(c.second % 2 == 0){
                ans += c.second;
            }
            else{
                ans += max(0, c.second - 1);
                chk= 1;
            }
        }

        if(chk)
            ans++;

        return ans;
    }
};