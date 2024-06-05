class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();

        vector<vector<int>> vc(26, vector<int>(n, 0));

        // int total[26] = {0};
        for(int i =0; i < n; i++){
            // int cur[26] = {0};

            string t = words[i];
            for(char c : t){
                vc[c - 'a'][i] ++;
            }
        }

        vector<string> vs;
        for(int i =0; i < 26; i++){
            int er = INT_MAX;
            for(int j = 0; j < n; j++){
                er = min(er, vc[i][j]);
            }

            for(int r = 0; r < er; r++){
                string tr(1, char('a' + i));
                vs.push_back(tr);
            }
        }
        return vs;
    }
};