class Solution {
public:

    int calc_bits(int a){
        int res = 0;
        while(a > 0){
            if(a & 1)
                res++;
            a >>= 1;
        }
        return res;
    }

    static bool comp(pair<int, int> a, pair<int, int> b){
        if(a.second != b.second)
            return a.second < b.second;
        return a.first < b.first;
    }

    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();

        vector<pair<int, int>> vp(n);
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            vp[i] = {arr[i], calc_bits(arr[i])};
        }

        sort(vp.begin(), vp.end(), comp);
        for(int i = 0; i < n; i++){
            ans[i] = vp[i].first;
        }

        return ans;
    }
};