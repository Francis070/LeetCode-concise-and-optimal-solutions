class Solution {
public:

    void populate(vector<vector<int>> &v, vector<vector<int>>& mat){
        int n = mat.size(), m = mat[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int cur = 0;
                if((i- 1) >= 0)
                    cur += v[i-1][j];
                if( (j - 1) >=0 )
                    cur += v[i][j - 1];
                if((i - 1) >= 0 && (j - 1) >= 0)
                    cur -= v[i - 1][j - 1];
                
                cur += mat[i][j];
                v[i][j] = cur;
            }
        }
    }

    bool check(pair<int,int > top_left, pair<int, int> bottom_right, vector<vector<int>> &v){
        int tot = (bottom_right.first - top_left.first + 1);
        tot *= tot;

        int sum = v[bottom_right.first][bottom_right.second];
        if((top_left.first - 1) >= 0){
            sum -= v[top_left.first - 1][bottom_right.second];
        }
        
        if((top_left.second - 1) >= 0){
            sum -= v[bottom_right.first][top_left.second - 1];
        }

        if((top_left.first - 1) >= 0 && (top_left.second - 1) >= 0){
            sum += v[top_left.first - 1][top_left.second - 1];
        }

        // cout<<top_left.first<<" "<<top_left.second<<"--"<<bottom_right.first<<" "<<bottom_right.second<<"-->";
        // cout<<sum<<"&"<<tot<<endl;
        
        return sum == tot;
    }

    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> v(n, vector<int>(m, 0));
        int ans  = 0;

        populate(v, mat);

        for(int i =0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j]){
                    // cout<<i<<" "<<j<<endl;
                    int x = i, y = j;
                    while((x < n) && (y < m )
                    && check({i, j}, {x, y}, v)
                    ){
                        // vis[x][y] = 1;
                        x++; y++; 
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};