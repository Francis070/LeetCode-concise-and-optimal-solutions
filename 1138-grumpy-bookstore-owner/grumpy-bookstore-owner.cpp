# define ll long long int

class Solution {
public:
    int maxSatisfied(vector<int>& cust, vector<int>& gr, int k) {
        int n = cust.size();

        ll ans = 0;
        for(int i =0; i < n; i++){
            if(gr[i] == 0){
                ans+= cust[i];
            }
        }

        int j=0;
        int st = 0;
        ll cur = 0;
        ll rt = 0;
        while(j < n){
            if(gr[j] == 1){
                cur += cust[j];
            }   

            if(j >= k){
                if(gr[st] == 1){
                    cur -= cust[st];
                }
                st++;
            }

            if(j >= k - 1){
                rt = max(rt, cur);
            }
            j++;
        }


        ans += rt;

        return ans;
    }
};