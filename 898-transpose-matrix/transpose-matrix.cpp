class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size();

        vector<vector<int>> res(c, vector<int>(r, 0));

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                res[j][i] = mat[i][j];
            }
        }

        return res;
    }
};