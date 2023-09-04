class Solution {
public:

    int rec(int ind, int &val, vector<int> &ch, vector<int>& cookies, int n, int k){
        if(ind == n){
            int mx, mn;
            mx = *max_element(ch.begin(), ch.end());
            val = min(mx, val);
            // mn = *min_element(ch.begin(), ch.end());
            // vp.push_back(mx);
            // return mx - mn;
            return mx;
        }

        // if(dp[ind] != -1)
        //     return dp[ind];

        int ans = INT_MAX;
        for(int i = 0;i < k; i++){
            ch[i] += cookies[ind];
            int chk = rec(ind + 1, val, ch, cookies, n, k);
            ans = min(ans, chk);
            ch[i] -= cookies[ind];
        }

        return ans;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();

        vector<int> ch(k, 0);

        // vector<int> dp(10, -1);
        // vector<pair<int, int>> vp;
        int val = INT_MAX;
        int ans = rec(0, val, ch, cookies, n, k);
        
        // sort(vp.begin(), vp.end());
        // for(int i = 0;i < vp.size(); i++)
        //     cout<<vp[i].first<<" "<<vp[i].second<<endl;
        return val;
    }
};