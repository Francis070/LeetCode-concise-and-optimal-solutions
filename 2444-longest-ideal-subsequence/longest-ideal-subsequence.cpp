class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();

        vector<pair<char, int>> vc;
        unordered_map<int, int> um;
        for(int i =0; i < n; i++){
            char cur = s[i];
            // bool got = false;
            // int pos = -1, sz = -1;
            // for(int j = 0; j < vc.size(); j++){
            //     if(abs(cur - vc[j].first) <= k && vc[j].second > sz){
            //         pos = j;
            //         sz = vc[j].second;
            //         got = true;
            //     }
            // }
            // if(!got){
            //     vc.push_back({cur, 1});
            // }
            // else{
            //     vc[pos] = {cur, sz + 1};
            // }
            int cm = 0;
            for(int j = max(97, int(cur) - k); j <= min(122, int(cur) + k); j++){
                if(um.find(j) != um.end()){
                    cm = max(cm, um[j]);
                }
            }

            um[int(cur)] = cm + 1;
        }



        int ans = 0;
        for(auto & x : um){
            ans = max(ans, x.second);
            // cout<<x.first<<" "<<x.second<<endl;
        }

        return ans;
    }
};