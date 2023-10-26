class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void getval(int fir, int sec,vector<vector<int>>& matrix, vector<vector<int>>& vis, vector<vector<int>>& val){

        if(vis[fir][sec] == -1){
            return;
        }

        int m = matrix.size(), n = matrix[0].size();

        for(int i =0; i < 4; i++){
            int x = fir + dirs[i].first;
            int y = sec + dirs[i].second;

            if(x < m && x >= 0 && y < n && y >= 0 && matrix[x][y] > matrix[fir][sec]){
                getval(x, y, matrix, vis, val);
                val[fir][sec] = max(val[fir][sec], 1 + val[x][y]);
            }
        }

        vis[fir][sec] = -1;
        return;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0)), val(m, vector<int>(n, 1));

        for(int i =0; i < m; i++){
            for(int j = 0; j< n; j++){
                if(vis[i][j] == 0){
                    getval(i, j, matrix, vis, val);
                }
            }
        }   
        int ans = 1;
        for(int i  = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                ans = max(ans, val[i][j]);
        
        // for(int i  = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //        cout<<val[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return ans;

    }
};