class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m * n != original.size())
            return {};
        vector<vector<int>> ans(m, vector<int>(n));
        int x = 0, y = 0;
        for(int i = 0; i < original.size(); i++){
            ans[i/n][i % n] = original[i];
        }

        return ans;
    }
};