class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> uv;

        for(int i = 0; i < t.size(); i++)
            uv[t[i]].push_back(i);

        int low = -1;
        for(int i = 0; i < s.size(); i++){
            if(uv.find(s[i]) != uv.end()){
                int x = lower_bound(uv[s[i]].begin(), uv[s[i]].end(), low) - uv[s[i]].begin();
                if(x < uv[s[i]].size() && low == uv[s[i]][x]){
                    low++;
                    x = lower_bound(uv[s[i]].begin(), uv[s[i]].end(), low) - uv[s[i]].begin();
                }
                if(x == uv[s[i]].size())
                    return false;
                else 
                    low = uv[s[i]][x];
            }
            else
                return false;
        }

        return true;
    }
};