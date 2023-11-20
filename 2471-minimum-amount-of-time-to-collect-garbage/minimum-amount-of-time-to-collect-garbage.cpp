class Solution {
public:

    int chk(char col, string s){
        int cnt = 0;
        for(char c : s){
            if(c == col)
                cnt++;
        }
        return cnt;
    }

    int cost(char col, vector<string>& gar, vector<int>& travel){
        
        int res = 0, cur = 0, n = gar.size();

        for(int i = 0; i < n; i++){
            if(i != 0)
                cur += travel[i-1];
            int k = chk(col, gar[i]);
            if(k != 0){
                res += (k + cur);
                cur = 0;
            }
        }

        return res;
    }

    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // int n = garbage.size();
        int ans = 0;
        // for G
        ans += cost('G', garbage, travel);
        // int val = cost('G', garbage, travel);
        // cout<<val;

        //for P
        ans += cost('P', garbage, travel);

        // for M
        ans += cost('M', garbage, travel);

        return ans;
    }
};