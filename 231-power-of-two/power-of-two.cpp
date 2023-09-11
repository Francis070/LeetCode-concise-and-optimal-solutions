class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long cnt =0;
        long long k = abs(n);
        // n = abs(n);
        // cout<<k;
        while(k != 0){
            if(k & 1 == 1)
                cnt++;
            k >>= 1;
        }

        if(cnt == 1 && n > 0)
            return true;
        return false;
    }
};

// -2147483648