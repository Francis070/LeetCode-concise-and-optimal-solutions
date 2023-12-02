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
            unordered_map<char, int> temp;
            int sz = words[i].size();
            bool chk = true;
            for(int k = 0; k < sz; k++){
                temp[words[i][k]]++;

                if(temp[words[i][k]] > um[words[i][k]]){
                    chk = false;
                    break;
                }
            }

            if(chk){
                ans += sz;
            }
        }

        return ans;
    }
};