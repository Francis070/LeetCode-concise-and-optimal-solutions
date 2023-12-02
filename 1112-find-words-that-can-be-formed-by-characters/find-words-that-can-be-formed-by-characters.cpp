class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int n = words.size();
        // unordered_map<char, int> um;
        int um[26] = {0};
        for(char c : chars){
            um[c - 'a']++;
        }
        int ans =0;
        for(int i = 0; i < n; i++){
            // unordered_map<char, int> temp;
            int temp[26] = {0};
            int sz = words[i].size();
            bool chk = true;
            for(int k = 0; k < sz; k++){
                temp[words[i][k] - 'a']++;

                if(temp[words[i][k] - 'a'] > um[words[i][k] - 'a']){
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