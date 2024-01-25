class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();

        vector<int> prev(n + 1, 0), cur(n + 1, 0);
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(text2[i] == text1[j]){
                    cur[j + 1] =  1 + prev[j];
                }
                else{
                    cur[j + 1] = max(cur[j], prev[j + 1]);
                }
                ans = max(ans, cur[j + 1]);
            }
            prev = cur;
            fill(cur.begin(), cur.end(), 0);
        }

        return ans;
    }
};