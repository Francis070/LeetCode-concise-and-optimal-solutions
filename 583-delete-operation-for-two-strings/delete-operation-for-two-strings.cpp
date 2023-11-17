class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
        int cnt = 0;
        string s;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i - 1] == word2[j - 1]){
                    v[i][j] = v[i-1][j-1] + 1;
                    s += word1[i-1];
                }
                else{
                    v[i][j] = max(v[i][j-1], v[i-1][j]);
                }
                cnt = max(cnt, v[i][j]);
            }
        }
        // cout<<cnt<<" "<<s<<endl;

        // for(int i =0; i <= n; i++){
        //     for(int j = 0; j <= m; j++)
        //     {
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return n - cnt + m - cnt;

    }
};