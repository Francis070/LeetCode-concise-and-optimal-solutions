class Solution {
public:
    int maxProfitAssignment(vector<int>& dif, vector<int>& pro, vector<int>& wor) {
        int n = pro.size();

        vector<pair<int, int>> vp(n);
        int m = wor.size();
        for(int i = 0; i < n; i++){
            vp[i].first = dif[i];
            vp[i].second = pro[i];
        }
        vector<int> mxp(n);
        sort(vp.begin(), vp.end());
        sort(begin(dif), end(dif));
        int mx = -1;
        for(int i = 0; i < n; i++){
            mx = max(mx, vp[i].second);
            mxp[i] = mx;
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            
            int pos = upper_bound(begin(dif), end(dif), wor[i]) - begin(dif);
            pos --;
            // if(pos == 0 && dif[0] > wor[i]){
            //     ans += 0;
            // }

            // if(pos == n || dif[pos] > wor[i])
            //     pos--;

            if(pos >= 0 && pos < n){
                ans += mxp[pos];
            }

            // cout<<wor[i]<<" "<<pos<<endl;
        }

        return ans;
    }
};