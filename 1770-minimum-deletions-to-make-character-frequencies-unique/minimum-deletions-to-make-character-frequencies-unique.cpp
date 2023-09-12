class Solution {
public:
    int minDeletions(string s) {
        vector<int> v;
        unordered_map<char, int> um;
        for(char c : s)
            um[c]++;
        for(auto &x : um)
            v.push_back(x.second);
        
        sort(v.begin(), v.end(), greater<int>());
        int ans = 0;
        for(int i = 1; i < v.size(); i++){
            int x = max(0, v[i-1] - 1);
            if(v[i-1] <= v[i]){
                ans += abs(v[i] - x);
                v[i] = x;
            }
        }

        return ans;
    }
};