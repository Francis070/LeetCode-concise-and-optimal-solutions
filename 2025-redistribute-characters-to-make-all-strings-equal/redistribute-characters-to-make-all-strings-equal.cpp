class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();

        // vector<pair<string, bool>> vs(n);
        unordered_map<char, int> um;
        for(int i =0; i < n; i++){
            for(char c : words[i]){
                um[c]++;
            }
        }

        for(auto &x : um){
            if(x.second % n != 0)
                return false;
        }

        return true;
    }
};