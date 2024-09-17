class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> sc1, sc2;
        string cu= "";
        for(auto x : s1){
            if(x == ' '){
                sc1[cu]++;
                cu = "";
            }
            else{
                cu+=x;
            }
        }
        sc1[cu]++;
        cu = "";
        for(auto x : s2){
            if(x == ' '){
                sc2[cu]++;
                cu = "";
            }
            else{
                cu+=x;
            }
        }
        sc2[cu]++;

        vector<string> ans;
        for(auto x : sc1){
            if(x.second == 1 && sc2.count(x.first) == 0){
                ans.push_back(x.first);
            }
        }
        for(auto x : sc2){
            if(x.second == 1 && sc1.count(x.first) == 0){
                ans.push_back(x.first);
            }
        }

        return ans;
    }
};