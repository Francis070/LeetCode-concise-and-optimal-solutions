class Solution {
public:
    int maxScore(string s) {
        int n = s.size();

        int cnt_z = 0, cnt_o = 0, ans = INT_MIN;
        for(int i = 0; i < n; i++){
            if(s[i] == '0')
                cnt_z++;
            else
                cnt_o++;
            
            if(i != s.size() - 1){
                ans = max(ans, cnt_z - cnt_o);
            }
        }

        return ans + cnt_o;
    }
};