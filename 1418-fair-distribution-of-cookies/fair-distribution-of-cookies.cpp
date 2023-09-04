class Solution {
public:

    void rec(int ind, int &val, vector<int> &ch, vector<int>& cookies, int n, int k){
        if(ind == n){
            int mx, mn;
            mx = *max_element(ch.begin(), ch.end());
            val = min(mx, val);
            return;
        }

        for(int i = 0;i < k; i++){
            ch[i] += cookies[ind];
            rec(ind + 1, val, ch, cookies, n, k);
            ch[i] -= cookies[ind];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();

        vector<int> ch(k, 0);

        int val = INT_MAX;
        rec(0, val, ch, cookies, n, k);
        
        return val;
    }
};