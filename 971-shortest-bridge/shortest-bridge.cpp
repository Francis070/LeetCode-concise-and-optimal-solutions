class Solution {
public:
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    queue<pair<int, int>> get(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& vis){
        vis[x][y] = 1;
        int n = grid.size();
        queue<pair<int, int>> q, res;

        q.push({x, y});
        res.push({x, y});
        while(!q.empty()){
            pair<int, int> node = q.front();
            q.pop();

            for(int i =0; i < 4; i++){
                int a = node.first + dirs[i].first;
                int b = node.second + dirs[i].second;

                if(a >=0 && a < n && b >= 0 && b < n && vis[a][b] == 0 && grid[a][b] == 1){

                        vis[a][b] = 1;
                        q.push({a, b});
                        // cout<<a<<" "<<b<<endl;
                        res.push({a, b});

                }
            }
        }
        // cout<<res.siz/e();
        return res;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        
        vector<vector<int>> vis(n, vector<int>(n, 0)); 
        for(int i = 0; i < n; i++){
            bool chk = false;
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q = get(i, j, grid, vis);
                    chk = true;
                    break;
                }
            }
            if(chk)
                break;
        }

        // while(!q.empty()){
        //     pair<int, int> x = q.front();
        //     cout<<x.first<<" "<<x.second<<endl;
        //     q.pop();
        // }

        int dist = 0;
        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                pair<int, int> node = q.front();
                q.pop();
                
                for(int i = 0; i < 4; i++){
                    int x = node.first + dirs[i].first;
                    int y = node.second + dirs[i].second;

                    if(x >=0 && x < n && y >= 0 && y < n && !vis[x][y]){
                        if(grid[x][y] == 1){
                            return dist;
                        }
                        else{
                            vis[x][y] = 1;
                            q.push({x, y});
                        }
                    }
                }
            }
            dist++;
        }

        return -1;
    }
};