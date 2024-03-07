#define ll long long
class Solution {
public:
    int divide(int dividend, int divisor) {
        ll divd = dividend, divs = divisor;
        ll cur = divd/divs;

        // cout<<cur<<endl;
        ll mn = -1* pow(2, 31);
        ll mx = pow(2, 31) - 1;
        // cout<<mn<<" "<<mx<<endl;
        ll ans = cur;
        ans = min(ans, mx);
        ans = max(ans, mn);
        return ans;
    }
};