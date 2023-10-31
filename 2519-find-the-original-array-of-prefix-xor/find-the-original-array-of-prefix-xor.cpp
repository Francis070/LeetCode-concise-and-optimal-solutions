class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        // vector<int> ans(n);
        // ans[0] = pref[0];
        int x = 0;
        for(int i =1 ; i < n; i++){
            // ans[i] = pref[i] ^ pref[i-1];
            x ^= pref[i-1] ;
            pref[i] = pref[i] ^ x;
        }

        return pref;
    }
};