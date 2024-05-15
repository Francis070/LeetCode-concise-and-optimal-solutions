class Solution {
public:

    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool check(vector<vector<int>> &distance, int mid){
        int n = distance.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<pair<int, int>> q;
        if(distance[0][0] >= mid){
            visited[0][0] = 1;
            q.push({0, 0});
        }
        else{
            return false;
        }

        while(!q.empty()){
            pair<int, int> cur = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int x = cur.first+ directions[i].first;
                int y = cur.second + directions[i].second;

                if(x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && distance[x][y] >= mid){
                    visited[x][y] = 1;
                    q.push({x, y});
                    if(x == n-1 && y == n-1)
                        return true;
                }
            }
        }

        return false;
    }

    vector<vector<int>> getDistance(vector<vector<int>>& grid){
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
                    int x = cur.first + directions[i].first;
                    int y = cur.second + directions[i].second;

                    if(x >= 0 && x < n && y >= 0 && y < n && dis[x][y] == INT_MAX){
                        dis[x][y] = cnt;
                        q.push({x, y});
                    }
                }
            }
        }

        return dis;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> distance = getDistance(grid);

        int low = INT_MAX, high = INT_MIN;
        //finding low and high for binary search

        for(int i =0; i < n; i++){
            for(int j = 0; j < n; j++){
                low = min(low, distance[i][j]);
                high = max(high, distance[i][j]);
            }
        }

        // binary search
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(check(distance, mid)){
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