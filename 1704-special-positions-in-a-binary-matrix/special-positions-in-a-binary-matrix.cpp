class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector<int> a(n, 0), b(m, 0);
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < m; j++){
                if(mat[i][j]) cnt++;
            }
            a[i] = cnt;
            // if(cnt == 1)
            //     av++;
        }

        for(int i = 0; i < m; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(mat[j][i]) cnt++;
            }
            b[i] = cnt;
            // if(cnt == 1)
            //     bv++;
        }
        int ans = 0;
        for(int i= 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(a[i] == 1 && b[j] == 1 && mat[i][j]){
                    // cout<<i<<"-"<<j<<endl;
                    ans++;
                    // break;
                }
            
        return ans;
    }
};