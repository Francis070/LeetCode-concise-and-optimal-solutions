class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        string r = s;
        reverse(r.begin(), r.end());
        vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j<= n; j++){
                if(s[i-1] == r[j-1]){
                    v[i][j] = max(v[i-1][j-1] + 1, max(v[i-1][j], v[i][j-1]) );
                }
                else{
                    v[i][j] = max(v[i-1][j], v[i][j-1]);
                }
            }
        }

        int val = v[n][n];
        return n - val;
    }
};