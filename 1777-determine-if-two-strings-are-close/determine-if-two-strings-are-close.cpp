class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int w1 = word1.size(), w2 = word2.size();

        if(w1 != w2)
            return false;

        set<char> s1, s2;
        unordered_map<char, int> um1, um2;
        for(char c : word1){
            s1.insert(c);
            um1[c]++;
        }
        for(char c : word2){
            s2.insert(c);
            um2[c]++;
        }

        vector<int> v1, v2;
        for(auto x : um1)
            v1.push_back(x.second);
        
        for(auto x : um2)
            v2.push_back(x.second);
        
        sort(begin(v1), end(v1));
        sort(begin(v2), end(v2));
        if(s1 != s2 || v1 != v2)
            return false;

        return true;
    }
};