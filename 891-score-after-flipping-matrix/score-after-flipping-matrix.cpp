class Solution {
public:

    void toggle(vector<vector<int>>& grid, int row, int col){
        int n = grid.size(), m = grid[0].size();

        if(row != -1){
            for(int i = 0; i < m; i++){
                if(grid[row][i] == 1)
                    grid[row][i] = 0;
                else
                    grid[row][i] = 1;
            }
        }
        else{
            for(int i = 0; i < n; i++){
                if(grid[i][col] == 1)
                    grid[i][col] = 0;
                else
                    grid[i][col] = 1;
            }
        }
    }

    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // checking for the first bit
        for(int i = 0; i < n; i++){
            if(grid[i][0] != 1){
                toggle(grid, i, -1);
            }
        }

        // checking the consecutive bits on the basis of count
        for(int i = 1; i < m; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(grid[j][i])
                    cnt++;
            }
            if(cnt <= n/2){
                toggle(grid, -1, i);
            }
        }
        int val = 0;
        for(int i =0; i<n; i++){
            for(int j =0; j < m; j++){
                int ind = m - 1 - j;
                if(grid[i][j])
                    val += pow(2, ind);
            }
        }

        // for(int i =0; i<n; i++){
        //     for(int j =0; j < m; j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return val;
    }
};