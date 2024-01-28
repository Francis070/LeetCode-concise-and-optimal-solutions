class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int tar) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> vc(n, vector<int>(m, 0));
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                vc[i][j] = mat[i][j];

                if(i - 1 >=0) vc[i][j] += vc[i-1][j];
                if(j - 1 >= 0) vc[i][j] += vc[i][j-1];
                if(i - 1 >= 0 && j - 1 >= 0) vc[i][j] -= vc[i-1][j-1];

                if(vc[i][j] == tar )
                    ans++;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                cout<<vc[i][j]<<" ";
            cout<<endl;
        }

        for(int i = 0; i < n; i++){
            for(int j= 0; j < m; j++){

                int val = vc[i][j];

                 for(int q = 0; q < j; q++){
                    if(vc[i][j] - vc[i][q] == tar)
                        ans++;
                }
                for(int q = 0; q < i; q++){
                    if(vc[i][j] - vc[q][j] == tar)
                        ans++;
                }

                for(int a = 0; a < i; a++){
                    for(int b = 0; b < j; b++){
                        if((vc[i][j] - vc[a][j] - vc[i][b] + vc[a][b]) == tar)
                            ans++;
                    }
                }

            }
        }

        return ans;
    }
};