class Solution {
public:

    bool check(int x, int y, vector<vector<int>>& grid){
        int col = 0, row = 0;
        // int 
        for(int i = 0; i < 3; i++){
            col += grid[x + i][y];
            row += grid[x][y + i];
        }
        // cout<<col<<" "<<row<<endl;
        for(int i = 1; i < 3; i++){
            int temp = 0;
            for(int j = 0; j < 3; j++){
                temp += grid[x + i][y + j];
            }
            if(temp != row)
                return false;
        }

        for(int i = 1; i < 3; i++){
            int temp = 0;
            for(int j = 0; j < 3; j++){
                temp += grid[x + j][y + i];
            }
            if(temp != col)
                return false;
        }
        // cout<<"here"<<endl;
        int dig = 0;
        for(int i = 0; i < 3; i++){
            dig += grid[x + i][y + i];
        }
        int rdig = 0;
        for(int i =0; i < 3; i++){
            rdig += grid[x + i][y + 3 - i - 1];
        }
        // cout<<dig<<" "<<rdig<<endl;
        if(dig != rdig)
            return false;

        return true;
    }

    bool value(int x, int y, vector<vector<int>>& grid){
        set<int> st;
        for(int i =0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                st.insert(grid[x + i][y + j]);
            }
        }

        if(st.size() == 9 && *st.begin() == 1 && *prev(st.end()) == 9){
            return true;
        }

        return false;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i =0 ; i <= n - 3; i++){
            for(int j = 0; j <= m - 3; j++){
                if(check(i, j, grid) && value(i, j, grid)){
                    ans++;
                }
            }
        }

        return ans;
    }   
};