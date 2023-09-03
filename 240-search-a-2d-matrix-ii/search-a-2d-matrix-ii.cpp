class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int r = mat.size(), c = mat[0].size();

        int i = r-1, j = 0;

        while(i >= 0 && i < r && j >= 0 && j < c){
            if(mat[i][j] == target)
                return true;

            if(mat[i][j] < target)
                j++;
            else
                i--;
        }

        return false;
    }
};