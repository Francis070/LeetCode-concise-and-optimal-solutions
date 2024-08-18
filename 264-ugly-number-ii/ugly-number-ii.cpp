class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> v;
        v.push_back(1);
        int c2 = 0, c3 = 0, c5 = 0;
        
        while(v.size() < n){
            long long val = 1e10;
            val = min(val, 2 * v[c2]);
            val = min(val, 3 * v[c3]);
            val = min(val, 5 * v[c5]);

            v.push_back(val);

            if(2 * v[c2] <= val)
                c2++;
            if(3 * v[c3] <= val)
                c3++;
            if(5 * v[c5] <= val)
                c5++;
        }

        return v.back();
    }
};