class Solution {
public:

    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool chk(vector<vector<int>> &dis, int mid){
        int n = dis.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<int, int>> q;
        if(dis[0][0] >= mid){
            vis[0][0] = 1;
            q.push({0, 0});
        }
        else{
            return false;
        }

        while(!q.empty()){
            pair<int, int> cur = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int x = cur.first+ dirs[i].first;
                int y = cur.second + dirs[i].second;

                if(x >= 0 && x < n && y >= 0 && y < n && vis[x][y] == 0 && dis[x][y] >= mid){
                    vis[x][y] = 1;
                    q.push({x, y});
                    if(x == n-1 && y == n-1)
                        return true;
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        for(int i =0; i< n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    dis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        
        int cnt = 0;
        while(!q.empty()){
            cnt++;
            int sz = q.size();

            while(sz--){
                pair<int, int> cur = q.front();
                q.pop();

                for(int i =0; i< 4; i++){
                    int x = cur.first + dirs[i].first;
                    int y = cur.second + dirs[i].second;

                    if(x >= 0 && x < n && y >= 0 && y < n && dis[x][y] == INT_MAX){
                        dis[x][y] = cnt;
                        q.push({x, y});
                    }
                }
            }
        }
        int low = INT_MAX, high = INT_MIN;
        for(int i =0; i < n; i++){
            for(int j = 0; j < n; j++){
                low = min(low, dis[i][j]);
                high = max(high, dis[i][j]);
            }
        }
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(chk(dis, mid)){
                ans = max(ans, mid);
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
};