class Solution {
public:

    void rec(int ind, int m, int cur, int &ans,vector<int> delta, vector<vector<int>>& req){
        if(ind >= m){
            bool chk = true;
            for(int i = 0; i < delta.size(); i++){
                if(delta[i] != 0){chk = false; break;}
            }
            if(chk){
                ans = max(ans, cur);
            }

            return ;
        }


        //don't take the request

        rec(ind + 1, m, cur, ans, delta, req);

        //take the req
        int a = req[ind][0], b = req[ind][1];
        delta[a]--;
        delta[b]++;
        rec(ind + 1, m, cur + 1, ans, delta, req);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> delta(n, 0);
        int m = requests.size();
        int ans = 0;
        rec(0, m, 0, ans,delta, requests);

        return ans;
    }
};