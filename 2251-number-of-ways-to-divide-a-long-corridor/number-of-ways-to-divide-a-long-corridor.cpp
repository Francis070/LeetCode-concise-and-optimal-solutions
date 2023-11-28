class Solution {
public:
    int numberOfWays(string cor) {
        int n = cor.size();

        int cnt_s = 0;
        int mod = 1e9 + 7;
        for(int i = 0; i < n; i++)
            if(cor[i] == 'S')
                cnt_s++;
        
        if(cnt_s % 2 != 0 || cnt_s < 2){
            return 0;
        }
        if(cnt_s == 2)
            return 1;

        int s_cal = 0;
        int g_cal = 0;
        long long ans = 1;
        
        for(int i = 0; i < n; i++){
            if(cor[i] == 'S'){
                if((s_cal == 2)){
                    ans = (ans * (g_cal + 1))%mod;
                    s_cal = 0;
                    g_cal = 0;
                }
                s_cal += 1;
            }
            else{
                if(s_cal == 2)
                    g_cal++;
            }
            // cout<<s_cal<<" "<<g_cal<<endl;
        }

        return ans;
    }
};