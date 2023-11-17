class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int cnto = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                cnto++;
            }
            else{
                ans = min(cnto, 1 + ans);
            }
        }
        return ans;
    }
};