class Solution {
public:

    bool check(int r, int c, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& vis){
        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int n = grid1.size(), m = grid1[0].size();
        queue<pair<int, int>> q;

        q.push({r, c});
        vis[r][c] = 1;
        bool val = true;
        if(grid1[r][c] == 0)
            val = false;
        while(!q.empty()){
            pair<int, int> cur = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int x = cur.first + dir[i].first;
                int y = cur.second + dir[i].second;

                if(x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0 && grid2[x][y] == 1){
                    if(grid1[x][y] == 0){
                        val = false;
                    }

                    vis[x][y] = 1;
                    q.push({x, y});
                }
            }
        }

        return val;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for(int i= 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid2[i][j] == 1 && vis[i][j] == 0){
                    if(check(i, j, grid1, grid2, vis)){
                        ans++;
                    }
                    // else{
                    //     dam(i, j, grid2, vis);
                    // }
                }
            }
        }

        return ans;
    }
};