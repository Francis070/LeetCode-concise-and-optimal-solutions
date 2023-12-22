class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        for(int i = 0; i < n; i++){
            for(int j =0; j < m; j++){
                if(i == 0 || j == 0){
                    vector<int> t;
                    int x =i, y = j;
                    while(x < n && y < m){
                        t.push_back(mat[x++][y++]);
                    }
                    sort(t.begin(), t.end());
                    x =i; y = j;
                    for(int k  = 0; k < t.size(); k++){
                        mat[x++][y++] = t[k];
                    }
                }
            }
        }

        return mat;
    }
};