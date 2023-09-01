class Solution {
public:
    int maximumGroups(vector<int>& gra) {
        int n = gra.size();

        sort(gra.begin(), gra.end());

        int ans = 0, sz = 1;
        int i = 0;
        while(i + sz <= n){
            ans++;
            i += sz;
            sz++;
        }
        return ans;
    }
};


//3  5  6  7  10  12