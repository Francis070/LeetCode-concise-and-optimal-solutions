class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> v = mat;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                v[i][j] = 1e8;
                if(j == 0){
                    v[i][j] = min(v[i][j], mat[i][j] + v[i-1][j]);
                    if(j != m-1)
                        v[i][j] = min(v[i][j] , mat[i][j] + v[i-1][j+1]);
                }
                else if(j == m-1){
                    v[i][j] = min(v[i][j], mat[i][j] + v[i-1][j]);
                    if(j != 0)
                        v[i][j] = min(v[i][j] , mat[i][j] + v[i-1][j-1]);
                }
                else{
                    v[i][j] = mat[i][j] + min(v[i-1][j], min(v[i-1][j-1], v[i-1][j + 1]));
                }
            }
        }

        int ans =INT_MAX;
        for(int i =0; i < m; i++){
            ans = min(ans, v[n-1][i]);
        }

        return ans;
    }
};