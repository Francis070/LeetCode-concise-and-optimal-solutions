class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();

        vector<string> bucket(n + 1, "");
        unordered_map<char, int> um;

        for(char c : s)
            um[c]++;

        for(auto &x : um){
            int f = x.second;
            char d = x.first;
            bucket[f].append(f, d);
        }
        string res = "";
        for(int i = n; i > 0; i--){
            if(bucket[i].size() > 0){
                res += bucket[i];
            }
        }

        return res;
    }
};