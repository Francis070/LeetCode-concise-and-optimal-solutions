class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();

        int ans = 0;

        string t = s;
        for(int i = 0; i < n; i++){
            if(s[i] == 'b'){
                t = t.substr(i, n - i);
                break;
            }
        }
        int cnt_a = 0, cnt_b = 0;
        for(int i = 0; i < t.size(); i++){
            if(t[i] == 'a'){
                cnt_a++;
                
                if(cnt_b > 0){
                    ans = min(min(cnt_a, cnt_b), ans + 1);
                }
            }
            else{
                cnt_b++;
            }
        }

        // ans = min(cnt_a, cnt_b);

        return ans;
    }
};