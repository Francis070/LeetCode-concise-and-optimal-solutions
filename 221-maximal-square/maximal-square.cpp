class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> v(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j< m; j++){
                if(mat[i][j] == '1')
                    v[i][j] = 1;
                else
                    v[i][j] = 0;
            }
        }
        int l = 0;
        for(int i = 0; i < n; i++){
            if(v[i][0])
                l = 1;
        }
        for(int i = 0; i < m; i++){
            if(v[0][i])
                l = 1;
        }
        // int l = 0;
        for(int i =1; i < n; i++){
            for(int j = 1; j< m; j++){
                int val = 0;
                if(v[i][j] == 1)
                    val = min(v[i-1][j-1], min(v[i-1][j], v[i][j-1]));
                if(val > 0){
                    v[i][j] = val + 1;
                }

                l = max(l, v[i][j]);
            }
        }

        return (l * l);
    }
};