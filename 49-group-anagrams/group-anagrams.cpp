class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& words) {
        int n = words.size();

        unordered_map<string, vector<string>> vs;

        for(int i =0; i < n; i++){

            string temp = words[i];
            sort(temp.begin(), temp.end());
            vs[temp].push_back(words[i]);

        }

        vector<vector<string>> ans;

        for(auto x : vs){
            ans.push_back(x.second);
        }

        return ans;
    }
};

/*
complexities = 
time =  N * MlogM
space = N*M
*/