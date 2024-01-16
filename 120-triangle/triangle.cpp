class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        vector<vector<int>> v = tri;
        int n=tri.size();
        for(int i = 1; i < n; i++){
            for(int j = 0; j < tri[i].size(); j++) {
                // v[i][j] = 0;
                v[i][j] = 1e8;
                int us = v[i-1].size();
                if(j >= 0 && j < us){
                    v[i][j] = min(v[i][j], tri[i][j] + v[i-1][j]);
                }
                if(j - 1 >=0 && j-1 < us){
                    v[i][j] = min(v[i][j], v[i-1][j-1] + tri[i][j]);
                }
            }
        }

        // for(int i =0; i < n; i++){
        //     for(int j = 0; j< v[i].size(); j++)
        //         cout<<v[i][j]<<" ";
        //     cout<<endl;
        // }

        int ans =INT_MAX;
        for(int i =0; i < tri[n-1].size(); i++){
            ans = min(ans, v[n-1][i]);
        }

        return ans;
    }
};