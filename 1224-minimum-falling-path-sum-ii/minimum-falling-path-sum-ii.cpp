class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> mat(n, vector<int>(n, 0));

        for(int i =0; i < n; i++)
            mat[0][i] = grid[0][i];
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                int mn = INT_MAX;
                for(int k = 0; k < n; k++){
                    if(k != j){
                        mn = min(mat[i-1][k], mn);
                    }
                }

                mat[i][j] = grid[i][j] + mn;
            }
        }

        // for(int i = 1; i < n; i++){
        //     for(int j = 0; j < n; j++){
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            ans = min(ans, mat[n-1][i]);
        }

        return ans;
    }
};