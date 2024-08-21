class Solution {
public:
    int strangePrinter(string s) {
        string ns = newString(s);

        int n = ns.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        int ans = findturns(ns, 0, n-1, dp);
        return ans;
    }

    string newString(string s){
        string res = "";

        for(char c : s){
            if(res.size() == 0){
                res += c;
            }
            else{
                if(c != res.back())
                    res += c;
            }
        }

        return res;
    }

    int findturns(string & s, int st, int en, vector<vector<int>> & dp){
        if(st > en)
            return 0;

        if(dp[st][en] != -1)
            return dp[st][en];

        int cur = 1 + findturns(s, st + 1, en, dp);

        for(int i = st + 1; i <= en; i++){
            if(s[i] == s[st]){
                int temp = findturns(s, st, i-1, dp) + findturns(s, i + 1, en, dp);

                cur = min(cur, temp);
            }
        }

        return dp[st][en] = cur;
    }
};