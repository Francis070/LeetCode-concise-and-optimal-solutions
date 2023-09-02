class Solution {
public:

    int rec(int ind, string s, unordered_map<string, int> &um, int n, vector<int> &dp){
        if(ind == n)
            return 0;

        if(dp[ind] != -1)
            return dp[ind];

        string temp = "";
        int ans = s.size();
        for(int i= ind; i < n; i++){
            temp += s[i];
            int chk = rec(i + 1, s, um, n, dp);

            int cur = temp.size();
            if(um[temp] > 0)
                cur = 0;

            ans = min(ans, cur + chk);
        }

        return dp[ind] = ans;
    }
    
    int minExtraChar(string s, vector<string>& dic) {
        int n = s.size();
        unordered_map<string, int> um;
        vector<int> dp(n + 1, 0);

        for(string x : dic){
            um[x]++;
        }

        // int ans = rec(0, s, um, n, dp);

        for(int i = n-1; i >= 0; i--){
            string temp = "";
            int ans = s.size();
            for(int j= i; j < n; j++){
                temp += s[j];
                // int chk = rec(j + 1, s, um, n, dp);
                int chk = dp[j + 1];

                int cur = temp.size();
                if(um[temp] > 0)
                    cur = 0;

                ans = min(ans, cur + chk);
            }

            dp[i] = ans;
        }

        return dp[0];
    }
};