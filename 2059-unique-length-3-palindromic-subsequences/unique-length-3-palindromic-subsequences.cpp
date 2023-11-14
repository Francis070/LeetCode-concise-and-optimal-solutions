class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        unordered_map<char, vector<int>> um;

        for(int i = 0; i < n; i++){
            char cur = s[i];
            if(um.find(cur) == um.end()){
                um[cur].push_back(i);
            }   
            else{
                if(um[cur].size() == 1)
                    um[cur].push_back(i);
                else
                    um[cur][1] = i;
            }
        }
        int ans = 0;
        for(auto &x : um){
            if(x.second.size() == 2){
                unordered_set<char> st;
                for(int i = x.second[0] + 1; i < x.second[1] ; i++){
                    st.insert(s[i]);
                }
                ans += st.size();
            }
        }

        return ans;
    }
};