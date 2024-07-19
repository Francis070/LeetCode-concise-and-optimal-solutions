class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        unordered_set<int> row, col;

        for(int i =0; i < n; i++){
            int cur = INT_MAX;
            for(int j = 0; j < m; j++){
                cur = min(cur, mat[i][j]);
            }
            row.insert(cur);
        }

        for(int i = 0; i < m; i++){
            int cur = INT_MIN;
            for(int j = 0; j < n; j++){
                cur = max(cur, mat[j][i]);
            }
            col.insert(cur);
        }

        vector<int> ans;

        for(auto & x : row){
            if(col.find(x) != col.end())
                ans.push_back(x);
        }

        return ans;
    }
};