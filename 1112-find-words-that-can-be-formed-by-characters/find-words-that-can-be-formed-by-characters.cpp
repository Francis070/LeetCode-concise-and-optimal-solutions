class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int n = words.size();
        unordered_map<char, int> um;
        for(char c : chars){
            um[c]++;
        }
        int ans =0;
        for(int i = 0; i < n; i++){
            unordered_map<char, int> temp = um;
            int sz = words[i].size();
            bool chk = true;
            for(int k = 0; k < sz; k++){
                if(temp.find(words[i][k]) == temp.end() || temp[words[i][k]] == 0){
                    chk = false;
                    break;
                }
                else{
                    temp[words[i][k]]-=1;
                }
            }

            if(chk){
                ans += sz;
            }
        }

        return ans;
    }
};