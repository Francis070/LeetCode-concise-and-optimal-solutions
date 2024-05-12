#define ll long long

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<pair<ll, ll>>> mat(n, vector<pair<ll, ll>>(m, {0, INT_MAX}));

        mat[0][0] = {grid[0][0], grid[0][0]};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mat[i][j].first = grid[i][j];
            }
        }

        for(int i =0 ; i < n; i++){
            for(int j = 0; j< m; j++){
                if(i == 0 && j == 0){
                    continue;
                }
                ll mn = INT_MAX;
                if(i-1 >= 0){
                    mn = min(mn, min(mat[i-1][j].first, mat[i-1][j].second));
                }
                if(j-1 >= 0){
                    mn = min(mn, min(mat[i][j-1].first, mat[i][j-1].second));
                }

                mat[i][j].second = mn;
            }
        }

        ll ans = INT_MIN;
        for(int i =0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0){
                    continue;
                }

                ans = max(ans, mat[i][j].first - mat[i][j].second);
            }
        }
        return ans;
    }
};