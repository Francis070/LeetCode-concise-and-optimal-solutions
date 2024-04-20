class Solution {
public:

    void remove(int tlx, int tly, int a, int b, vector<vector<int>>& land){
        for(int i = tlx; i <= a; i++){
            for(int j = tly; j <= b; j++){
                land[i][j] = 0;
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(land[i][j] == 1){
                    int tlx = i, tly = j;
                    int a = i, b = j;
                    while(a < n && land[a][j] == 1)
                        a++;
                    a--;
                    while(b < m && land[i][b] == 1)
                        b++;
                    b--;
                    remove(tlx, tly, a, b, land);
                    ans.push_back({tlx, tly, a, b});
                }
            }
        }

        return ans;
    }
};