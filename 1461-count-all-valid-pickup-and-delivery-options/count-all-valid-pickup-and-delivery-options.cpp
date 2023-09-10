class Solution {
public:
    int countOrders(int n) {
        long long ans = 1;
        int mod = 1e9 + 7;
        int m = 2 * n;

        while(m > 0){
            ans = (ans * ((m * (m-1))/2)) % mod;
            m-=2;
        }

        return ans;
    }
};