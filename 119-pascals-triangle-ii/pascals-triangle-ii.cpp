class Solution {
public:
    vector<int> getRow(int n) {
        n++;
        vector<vector<int>> v(n);

        v[0].push_back(1);

        for(int i = 1; i < n; i++){
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i){
                    v[i].push_back(1);
                }
                else{
                    v[i].push_back(v[i-1][j] + v[i-1][j-1]);
                }
            }
        }

        return v[n-1];
    }
};