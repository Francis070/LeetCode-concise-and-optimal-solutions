#define ll long long
class Solution {
public:
    int gre(ll a,ll b,ll &n){
        int gap=0; 
        while(a <= n){
            gap += min(n+1,b)-a;
            a*=10;
            b*=10;
        }
        return gap;
    }
    int findKthNumber(int n, int k) {
        ll num = 1;
        ll x = n;
        for(int i=1; i<k;){
            int req = gre(num,num+1,x);
            if(i+req <= k){
                i+=req;
                num++;
            }else{
                i++;
                num *= 10;
            }
        }
        return num;
    }
};