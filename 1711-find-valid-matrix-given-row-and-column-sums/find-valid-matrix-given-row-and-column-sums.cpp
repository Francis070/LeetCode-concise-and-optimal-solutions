class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();

        vector<vector<int>> v(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                v[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= v[i][j];
                colSum[j] -= v[i][j];
            }
        }

        return v;
    }
};