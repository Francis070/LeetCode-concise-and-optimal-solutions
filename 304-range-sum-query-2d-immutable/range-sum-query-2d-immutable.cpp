class NumMatrix {
public:
    vector<vector<int>> presum;
    NumMatrix(vector<vector<int>>& mat) {
        presum = mat;
        int r = mat.size(), c = mat[0].size();
        for(int i = 0; i < r; i ++){    
            for(int j =0;  j < c; j++){
                if(i-1 >= 0 && j-1 >= 0){
                    presum[i][j] = mat[i][j] + presum[i][j-1] + presum[i-1][j] - presum[i-1][j-1];
                }
                else if(i - 1 >= 0){
                    presum[i][j] = mat[i][j] +  presum[i-1][j];
                }
                else if(j-1 >= 0){
                    presum[i][j] = mat[i][j] +  presum[i][j-1];
                }
                else
                    presum[i][j] = mat[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int a, b, c;
        if(row1 - 1 >= 0 && col1 - 1 >= 0){
            a = presum[row1 - 1][col1 - 1];
            b = presum[row1 - 1][col2];
            c = presum[row2][col1 - 1];
        }
        else if(row1 - 1 >= 0){
            a = 0; b = presum[row1 - 1][col2];
            c = 0;
        }
        else if(col1 - 1 >= 0){
            a = 0; b = 0;
            c = presum[row2][col1 - 1];
        }
        else{
            a = 0; b = 0; c = 0;
        }

        return (presum[row2][col2] + a - b - c);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */