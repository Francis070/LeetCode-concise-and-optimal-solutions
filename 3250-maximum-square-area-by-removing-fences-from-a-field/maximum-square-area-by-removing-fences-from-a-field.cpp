class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hf, vector<int>& vf) {
        int mod = 1e9 + 7;
        
        hf.push_back(m);
        hf.push_back(1);
        vf.push_back(n);
        vf.push_back(1);
        
        sort(hf.begin(), hf.end());
        sort(vf.begin(), vf.end());
        
        int hs = hf.size(), vs = vf.size();
        
        // set<long long> st1, st2;
        unordered_map<int, int> um1, um2;
        for(int i = 0; i < hs; i++){
            for(int j = i+1; j < hs; j++){
                // st1.insert(abs(hf[j] - hf[i]));
                um1[abs(hf[j] - hf[i])] = 1;
            }
        }
        for(int i = 0; i < vs; i++){
            for(int j = i+1; j < vs; j++){
                // st2.insert(abs(vf[j] - vf[i]));
                um2[abs(vf[j] - vf[i])] = 1;
            }
        }
        long long ans = -1;
        for(auto & x : um1){
            long long val = x.first;
            if(um2.find(val) != um2.end()){
                long long e = (val * val * 1ll);
                ans = max(ans, (e));
            }
        }
        // for(auto x : st1){
        //     if(st2.find(x) != st2.end()){
        //         long long val = (x%mod * x%mod)%mod;
        //         ans = max(ans, val)%mod;
        //     }
        // }
        
        return ans%mod;
    }
};