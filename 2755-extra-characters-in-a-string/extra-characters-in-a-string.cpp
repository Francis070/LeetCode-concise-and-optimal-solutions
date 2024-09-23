class Solution {
public:

    int rec(int ind, string &s,  map<char, vector<string>> &mp, vector<int> & dp){
        int n = s.size();
        if(ind >= n){
            return 0;
        }

        if(dp[ind] != -1)
            return dp[ind];

        int cur = n - ind;
        if(mp.find(s[ind]) != mp.end()){
            for(auto & x : mp[s[ind]]){
                if((n - ind) >= x.size() && x == s.substr(ind, x.size())){
                    cur = min(cur, rec(ind + x.size(), s, mp, dp));
                }
            }
        }
        
        cur = min(cur, 1 + rec(ind + 1, s, mp, dp));
        
        return dp[ind] = cur;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        map<char, vector<string>> mp;
        int n = s.size();
        for(auto x : dictionary){
            mp[x[0]].push_back(x);
        }

        vector<int> dp(n, -1);

        int ans = rec(0, s, mp, dp);

        return ans;
    }
};