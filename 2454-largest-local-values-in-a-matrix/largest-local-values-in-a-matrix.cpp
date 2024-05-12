class Solution {
public:

    map<int, int> getMap(vector<vector<int>>& grid, int i, int j){
        //creating the map to store the frequency of the integers in the current 3x3 grid.
        map<int, int > mp;
        for(int s = i; s < i + 3; s++){
            for(int c = j; c < j + 3; c++){
                mp[grid[s][c]]++;
            }
        }

        return mp;
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n - 3 + 1, vector<int>(m - 3 + 1, 0));

        for(int i = 0; i <= n-3; i++){
            map<int, int > mp;
            for(int j = 0; j <= m-3; j++){
                if(j == 0){
                    mp = getMap(grid, i, j);
                    ans[i][j] = prev(mp.end())->first;
                }
                else{
                    for(int a = i; a < i + 3; a++){
                        mp[grid[a][j-1]]--;
                        mp[grid[a][j+2]]++;
                        if(mp[grid[a][j-1]] == 0)
                            mp.erase(grid[a][j-1]);
                        if(mp[grid[a][j+2]] == 0)
                            mp.erase(grid[a][j+2]);
                    }
                    ans[i][j] = prev(mp.end())->first;
                }
            }
        }

        return ans;
    }
};