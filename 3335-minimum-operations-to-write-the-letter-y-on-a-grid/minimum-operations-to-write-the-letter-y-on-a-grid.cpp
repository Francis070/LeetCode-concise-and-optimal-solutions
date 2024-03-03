class Solution {
public:
    
    int get_val(vector<int> & a, vector<int> & b){
        int ans = 0;
        priority_queue<pair<int, int>> f, s;
        for(int i = 0; i < 3; i++){
            f.push({a[i], i});
            ans += a[i];
        }
        for(int i = 0; i < 3; i++){
            s.push({b[i], i});
            ans += b[i];
        }
        
        if(f.top().second == s.top().second){
            int c1 = ans, c2 = ans;
            
            priority_queue<pair<int, int>> cf = f;
            priority_queue<pair<int, int>> cs = s;
            
            cs.pop();
            c1 = c1 - cf.top().first - cs.top().first;
            
            cf = f; cs = s;
            
            cf.pop();
            c2 = c2 - cs.top().first - cf.top().first;
            
            ans = min(c1, c2);
        }
        else{
            ans = ans - f.top().first - s.top().first;
        }
        
        return ans;
    }
     
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> ss(n, vector<int>(n, 0));
        
        vector<int> nty(3, 0), wy(3, 0);
        
        // marking the cell of Y in the grid
        int x = 0, y = 0;
        while(x < n/2 && y < n/2){
            wy[grid[x][y]]++;
            ss[x][y] = -1;
            x++;
            y++;
        }
        
        x = 0; y = n-1;
        while(y > n/2 && x < n/2){
            wy[grid[x][y]]++;
            ss[x][y] = -1;
            y--;
            x++;
        }
        
        x = n/2; y = n/2;
        while(x < n){
            wy[grid[x][y]]++;
            ss[x][y] = -1;
            x++;
        }
        
        // getting the data for cells thar are not in Y
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(ss[i][j] != -1){
                    nty[grid[i][j]]++;
                }
            }
        }
        
        // getting the result by comparing the numbers.
        int ans = get_val(nty, wy);
        
        return ans;
    }
};