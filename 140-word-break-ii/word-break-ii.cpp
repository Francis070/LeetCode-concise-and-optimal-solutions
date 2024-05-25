class Solution {
public:

    void rec(int ind, int n, string  & cur, string  & fullstr, set<string> &st, string s, vector<string> & ans){
        if(ind >= n){
            if(st.find(cur) != st.end()){
                string er = "";
                if(fullstr.size() == 0)
                    er = "";
                else
                    er = " ";
                fullstr += (er + cur);
                ans.push_back(fullstr);
            }
            
            return;
        }

        cur += s[ind];
        string temp = "";
        string tre = fullstr;
        if(st.find(cur) != st.end()){
            string er = "";
            if(fullstr.size() == 0)
                er = "";
            else
                er = " ";
            tre += (er + cur);
            rec(ind + 1, n, temp, tre, st, s, ans);
        }

        rec(ind + 1, n, cur, fullstr, st, s, ans);
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        set<string> dict;

        for(string e : wordDict){
            dict.insert(e);
        }

        vector<string> ans;
        string part = "";
        string full = "";
        rec(0, n, part, full, dict, s, ans);

        return ans;
    }
};