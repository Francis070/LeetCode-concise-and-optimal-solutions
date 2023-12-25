class Solution {
public:

    int rec(int ind, int n, string &s, vector<int> & dp){
        if(ind >= n){
            return 1;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        int current = 0;

        if(int(s[ind]) - 48 <= 2){
            if(int(s[ind]) - 48 == 0) return 0;

            if(int(s[ind]) - 48 == 1){
                current += rec(ind + 1, n, s, dp);
                if(ind + 1 < n)
                    current += rec(ind + 2, n, s, dp);
            }
            else{
                current += rec(ind + 1, n, s, dp);

                if(ind + 1 < n && s[ind + 1] <= '6'){
                    current += rec(ind + 2, n, s, dp);
                }
            }
        }
        else{
            current += rec(ind + 1, n, s, dp);
        }

        return dp[ind] = current;
    }

    int numDecodings(string s) {
        int n = s.size();

        vector<int> dp(n+1, -1);
        int val = rec(0, n, s, dp);
        return val;
    }
};