class Solution {
public:

    vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool check(int x, int y, int ind, string &word, vector<vector<int>> &vis, vector<vector<char>> & board){
        if(ind >= word.size())
            return true;

        int n = board.size(), m = board[0].size();

        bool cur = false;

        vis[x][y] = 1;

        for(int i = 0; i < 4; i++){
            int a = x + dir[i].first;
            int b = y + dir[i].second;

            if(a >= 0 && a < n && b >= 0 && b < m && vis[a][b] == 0 && board[a][b] == word[ind]){
                bool pre = true && check(a, b, ind + 1, word, vis, board);
                
                cur = cur || pre;
            }
        }
        vis[x][y] = 0;
        return cur;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i =0; i < n; i ++){
            for(int j = 0; j< m; j++){
                if(board[i][j] == word[0]){
                    vector<vector<int>> vis(n, vector<int>(m, 0));
                    if(check(i, j, 1, word, vis, board))
                        return true;
                }
            }
        }

        return false;
    }
};