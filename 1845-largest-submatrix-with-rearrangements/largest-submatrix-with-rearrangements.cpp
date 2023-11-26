class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> v(n);
        for(int i = 0; i < m; i++){
            int cnt = 0;
            for(int j = 0; j< n; j++){
                if(mat[j][i] == 1){
                    cnt++;
                }
                else{
                    cnt = 0;
                }
                if(cnt > 0)
                    v[j].push_back(cnt);
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            sort(v[i].begin(), v[i].end(), greater<int>());

            for(int j = 0; j < v[i].size(); j++){
                ans = max(ans, (j + 1) * v[i][j]);
            }
        }

        return ans;
    }
};