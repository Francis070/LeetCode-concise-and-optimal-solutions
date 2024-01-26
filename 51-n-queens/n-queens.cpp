class Solution {
public:

    bool possible(int x, int y, vector<vector<int>> &board){
        
        int n = board.size();
        int a = x, b = y;
        while(a >= 0 && b >= 0){
            if(board[a][b] == 1)
                return false;
            a--; b--;
        }
        a = x; b = y;
        while(a >= 0 && b < n){
            if(board[a][b] == 1)
                return false;
            a--; b++;
        }
        a = x; b = y;
        while(x >= 0){
            if(board[x][y] == 1)
                return false;
            x--;
        }

        return true;
    }

    vector<string> convert(int n,  vector<vector<int>> board){
        vector<string> res(n);
        for(int i =0 ; i < n; i++){
            string temp = "";
            for(int j = 0; j < n; j++){
                if(board[i][j] == 0) temp += '.';
                else
                    temp += 'Q';
            }
            res[i] = temp;
        }
        return res;
    }

    bool can_place(int x , int n, vector<vector<int>> board, vector<vector<string>> &ans){
        if(x == n){
            vector<string> temp = convert(n, board);
            ans.push_back(temp);
            return true;
        }
        // bool res = false;
        for(int i = 0; i < n; i++){
            if(possible(x, i, board)){
                board[x][i] = 1;
                bool chk = can_place(x + 1, n, board, ans);
                if(chk == false){
                    board[x][i] = 0;
                    continue;
                }
                // else{
                //     return true;
                // }
                
            }
        }

        return false;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<string>> ans;

        can_place(0, n, board, ans);

        // for(int i = 0; i < n; i++){
        //     vector<vector<int>> t_board = board;
        //     t_board[0][i] = 1;
        //     if(can_place(1, n, t_board)){
        //         vector<string> temp = convert(n, t_board);
        //         ans.push_back(temp);
        //     }
        // }

        return ans;
    }
};