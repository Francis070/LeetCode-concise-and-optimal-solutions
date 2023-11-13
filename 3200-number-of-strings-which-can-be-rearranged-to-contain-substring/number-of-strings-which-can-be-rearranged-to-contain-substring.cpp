class Solution {
public:
    long long mod = 1e9 + 7;
    long long pow(long long a, long long b){
        
        long long res = 1;
        while(b > 0){
            if(b & 1){
                res = (res%mod * a%mod)% mod;
            }
            a = ((a%mod) * (a%mod))% mod;
            b >>= 1;
        }
        return res%mod;
    }

    int stringCount(int n) {

        long count = 0, mod = 1e9 + 7;
        return ((
            + pow(26, n)
            - (n + 75) * pow(25, n - 1)
            + (2 * n + 72) * pow(24, n - 1)
            - (n + 23) * pow(23, n - 1)
        ) % mod + mod) % mod;
        
        // if(n < 4)
        //     return 0;

        // long long a = be(25, n),  b = (n * be(25, n-1))%mod, c = be(24, n),
        // d = (be(24, n) + (n * be(24, n-1))%mod)%mod, e = (be(23, b) + (n*be(23, n-1))%mod)%mod;
        // long long ans = be(26, n);
        // // ans = ans - a - a - (a + b) + c + d + d - e;
        // long long sub = be(25, n);
        // sub += be(25, n);
        // sub += (be(25, n) + (n * be(25, n-1))%mod)%mod;
        // sub -= be(24, n);
        // sub -= (be(24, n) + (n * be(24, n-1))%mod)%mod;
        // sub -= (be(24, n) + (n * be(24, n-1))%mod)%mod;
        // sub += (be(23, b) + (n*be(23, n-1))%mod)%mod;

        // return (ans%mod - sub%mod + mod)%mod;
    }
};