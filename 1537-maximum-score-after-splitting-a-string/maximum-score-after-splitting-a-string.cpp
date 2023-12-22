class Solution {
public:
    int maxScore(string s) {
        int n = s.size();

        int count_ones = 0, count_zeroes = 0;
        for(char c : s)
            if(c == '1') count_ones++;
        
        int ans = 0;
        for(int i = 0; i < n-1; i ++){
            if(s[i] == '0') count_zeroes++;
            else count_ones--;
            ans = max(ans, count_zeroes + count_ones);
        }

        return ans;
    }
};