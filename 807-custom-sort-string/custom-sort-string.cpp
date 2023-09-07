class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> um;

        for(char x : s)
            um[x]++;
        string res = "";
        for(char x : order ){
            if(um[x] > 0){
                for(int i = 0; i < um[x]; i++)
                    res += x;

                um[x] = 0;
            }
        }

        for(auto x : um){
            if(x.second > 0){
                for(int i = 0; i < x.second; i++)
                    res += x.first;
            }
        }

        return res;
    }
};