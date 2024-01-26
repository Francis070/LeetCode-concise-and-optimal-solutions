class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int r = mat.size(), c = mat[0].size();
        int ans = 0;
        vector<vector<int>> vc(r, vector<int>(c, 0));

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                vc[i][j] += mat[i][j];
                if(i-1 >= 0)
                    vc[i][j] += vc[i - 1][j];
                if(j - 1 >= 0)
                    vc[i][j] += vc[i][j-1];
                if(i - 1 >= 0 && j - 1 >= 0)
                    vc[i][j] -= vc[i-1][j-1];

                if(vc[i][j] == target)
                    ans++;
            }
        }

        for(int i =0 ;i < r; i++){
            for(int j = 0; j < c; j++){
                
                for(int q = 0; q < j; q++){
                    if(vc[i][j] - vc[i][q] == target)
                        ans++;
                }
                for(int q = 0; q < i; q++){
                    if(vc[i][j] - vc[q][j] == target)
                        ans++;
                }

                for(int a = 0; a < i; a++){
                    for(int b = 0; b < j; b++){
                        if((vc[i][j] - vc[a][j] - vc[i][b] + vc[a][b]) == target)
                            ans++;
                    }
                }
            }
        }

        return ans;
    }
};