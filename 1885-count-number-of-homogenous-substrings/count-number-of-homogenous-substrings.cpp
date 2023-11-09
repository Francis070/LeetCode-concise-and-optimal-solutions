class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size();
        long long int ans = n, cnt = 0, mod = 1e9 + 7;
        // int 
        char cur;
        for(int i = 0; i < n; i++){
            if(cur != s[i]){

                if(cnt >= 2){
                    // ans += ( ((cnt-1)*cnt)%mod )/2;
                    ans += (( ((cnt-1)%mod)* ((cnt)%mod) )/2 ) %mod;
                }
                cur = s[i];
                cnt = 1;
            }
            else{
                cnt++;
            }
            // cout<<cnt<<endl;
            ans %= mod;
        }
        cout<<cnt<<" "<<ans<<" ";
        if(cnt >= 2){

            ans += (( ((cnt-1)%mod)* ((cnt)%mod) )/2 ) %mod;
            ans %= mod;

        }

        return ans;
    }
};