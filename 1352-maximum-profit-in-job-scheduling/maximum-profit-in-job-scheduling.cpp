class Solution {
public:

    int rec(int ind, int n, vector<int>& st, vector<int>& et, vector<int>& pf, vector<int> &dp){
        if(ind >= n){
            return 0;
        }

        if(dp[ind] != -1)
            return dp[ind];

        //take the current job and add the profit.
        int str = st[ind], end = et[ind];
        int pos = lower_bound(st.begin(), st.end(), end) - st.begin();
        int take = pf[ind] + rec(pos, n, st, et, pf, dp);

        // don't take the current job and move forward.
        int nottake = rec(ind + 1, n, st, et, pf, dp);

        return dp[ind] = max(take, nottake);

    }

    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& pf) {
        int n = st.size();
        vector<pair<int , pair<int, int>>> vp(n);
        for(int i = 0; i < n; i++){
            vp[i].first = st[i];
            vp[i].second.first = et[i];
            vp[i].second.second = pf[i];
        }

        sort(vp.begin(), vp.end());
        for(int i= 0; i < n ;i++){
            st[i] = vp[i].first;
            et[i] = vp[i].second.first;
            pf[i] = vp[i].second.second;
        }

        vector<int> dp(n + 3, -1);
        int ans = rec(0, n, st, et, pf, dp);
        return ans;
    }
};