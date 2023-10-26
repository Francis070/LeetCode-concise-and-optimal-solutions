class Solution {
public:

    void rec(string s, int k, int &ans){
        if(s.size() <= 0)
            return;
        int n = s.size();
        unordered_map<char, int> um;
        for(int i =0; i < n; i++){
            um[s[i]]++;
        }
        int a = 0;
        bool chk = true;
        for(int i =0; i < n; i++){
            if(um[s[i]] < k){
                chk = false;
                rec(s.substr(a, i- a), k, ans);
                a = i+ 1;
            }
        }

        if(a != 0)
            rec(s.substr(a, n-a), k, ans);

        if(chk)
            ans = max(ans, n);

        return;
    }

    int longestSubstring(string s, int k) {
        int ans = 0;
        rec(s, k, ans);

        return ans;
    }
};