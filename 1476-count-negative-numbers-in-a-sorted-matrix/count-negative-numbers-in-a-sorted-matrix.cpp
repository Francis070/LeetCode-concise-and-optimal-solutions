class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int i = r-1, j = 0;
        int ans = 0;

        
        while(j < c){
            if(i >= 0 && grid[i][j] < 0){
                i--;
            }
            else{
                ans += (r - i - 1);
                // // i = r-1;
                // if(i < 0)
                j++;
            }
        }

        return ans;
    }
};