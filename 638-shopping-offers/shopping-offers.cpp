class Solution {
public:

    int rec(int ind, int n, int m, vector<int>& pr, vector<int> ne, vector<vector<int>>& sp, map<vector<int>, int> &mp){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(ne[i] > 0) cnt++;
        }

        if(ind >= m || cnt == 0){
            int val = 0;
            for(int i = 0; i < n; i++){
                if(ne[i] != 0) val += (ne[i] * pr[i]);
            }
            return val;
        }

        if(mp.find(ne) != mp.end()){
            return mp[ne];
        }

        int ans = INT_MAX;

        vector<int> temp = ne;
        bool chk = true;
        for(int i =0 ; i < n; i++){
            if(sp[ind][i] > ne[i]){
                chk = false;
                break;
            }
            else{
                temp[i] -= sp[ind][i];
            }
        }
        // select the special if it can be availed.
        if(chk){
            ans = min(ans, sp[ind][n] + rec(0, n, m, pr, temp, sp, mp));
        }
        // else{
        //dont select the special
        ans = min(ans, rec(ind + 1, n, m, pr, ne, sp, mp));

        return mp[ne] = ans;
    }

    int shoppingOffers(vector<int>& pr, vector<vector<int>>& sp, vector<int>& ne) {
        int n = pr.size();

        int m = sp.size();
        map<vector<int>, int> mp;

        int ans = rec(0, n, m, pr, ne, sp, mp);

        return ans;
    }
};