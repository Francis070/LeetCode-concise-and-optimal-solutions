class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> um;
        for(char c : s)
            um[c]++;
        
        vector<pair<int, char>> vp;
        for(auto & x : um)
            vp.push_back({x.second, x.first});

        sort(vp.begin(), vp.end(), greater<>());
        string res = "";
        for(int i = 0; i < vp.size(); i++){
            for(int j = 0; j < vp[i].first; j++){
                res += vp[i].second;
            }
        }

        return res;
    }
};