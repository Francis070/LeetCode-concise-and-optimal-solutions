class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();

        vector<int> len(n, 0);
        len[0] = 1;
        for(int i =1; i < n; i++){
            if(s[i] == s[i-1])
                len[i] = len[i-1] + 1;
            else
                len[i] = 1;
        }

        vector<vector<int>> v(26);
        for(int i = 0; i < n; i++){
            v[s[i] - 'a'].push_back(len[i]);
        }
        int ans = -1;
        for(int i =0; i < 26; i++){
            sort(v[i].begin(), v[i].end(), greater<int>());
            if(v[i].size() >= 3){
                ans = max(ans, v[i][2]);
            }
        }

        return ans;
    }
};