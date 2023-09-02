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
            // dp[i] = chk;
            // if(dp.find(s.substr(ind + 1, n - temp.size())) == dp.end()){
            //     chk = 
            //     dp[s.substr(ind + 1, n - temp.size())] = chk;
            // }
            // else
            //     chk = dp[s.substr(ind + 1, n - temp.size())];

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
        vector<int> dp(n + 1, -1);

        for(string x : dic){
            um[x]++;
        }
        int ans = rec(0, s, um, n, dp);
        // for(auto & x : dp){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        return ans;
    }
};