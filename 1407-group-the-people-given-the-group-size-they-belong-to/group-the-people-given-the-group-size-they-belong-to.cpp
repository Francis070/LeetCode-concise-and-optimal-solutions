class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        int n = gs.size();
        unordered_map<int, vector<int>> um;
        for(int i = 0; i < n; i++){
            um[gs[i]].push_back(i);
        }

        vector<vector<int>> ans;

        for(auto &x : um){
            int g = x.first;
            for(int i = 0; i < x.second.size()/g; i++){
                vector<int> temp;
                for(int j =0; j < g; j++)
                    temp.push_back(x.second[(i * g) + j]);
                ans.push_back(temp);
            }
        }

        return ans;
    }
};