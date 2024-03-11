class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> um;

        for(int i = 0; i < order.size(); i++)
            um[order[i]] = i;
        
        vector<pair<int, char>> vc;
        string res = "";

        for(char c : s){
            if(um.find(c) != um.end())
                vc.push_back({um[c], c});
            else
                res += c;
        }

        sort(begin(vc), end(vc), greater<pair<int, char>>());
        for(int i = 0; i < vc.size(); i++){
            res = vc[i].second + res;
        }

        return res;
    }
};