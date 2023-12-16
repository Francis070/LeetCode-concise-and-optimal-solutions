class Solution {
public:
    int len(int i, int j, int n, pair<int, int> dir, vector<vector<int>> &v){
        int cnt = 1;
        while((i + dir.first < n) && (i + dir.first >= 0) && (j + dir.second < n) && (j + dir.second >= 0) && (v[i + dir.first][j + dir.second] == 1)){
            cnt++;
            i += dir.first;
            j += dir.second;
        }
        return cnt;
    }
    
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int m= mines.size();
        vector<vector<int>> v(n, vector<int>(n, 1));

        vector<vector<pair<int, int>>> hor(n, vector<pair<int, int>>(n)), ver(n, vector<pair<int, int>>(n));
        for(int i = 0; i < m; i++){
            int x = mines[i][0], y = mines[i][1];
            v[x][y] = 0;
            hor[x][y] = {0,0};
            ver[x][y] = {0,0};
        }

        // for(int i = 0;  i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        int ans = 0;
        
        // hor
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt = 0;
            int st = -1, en = -1;
            for(int j = 0; j < n; j++){
                if(v[i][j] == 1 && cnt == 0){
                    cnt = len(i, j, n, {0, 1}, v); 
                    st = j;
                    en = j + cnt - 1;
                    hor[i][j] = {st, en};
                }
                else{
                    if(cnt != 0 && v[i][j] == 1){
                        hor[i][j] = {st, en};
                    }
                    else if (v[i][j] == 0){
                        cnt = 0;
                    }
                }
            }
        }
    
        cnt = 0;
        for(int i = 0; i< n; i++){
            cnt = 0;
            int st = -1, en = -1;
            for(int j =0; j < n; j++){
                if(v[j][i] == 1 && cnt == 0){
                    cnt = len(j, i, n, {1, 0}, v); 
                    st = j;
                    en = j + cnt - 1;
                    ver[j][i] = {st, en};
                }
                else{
                    if(cnt != 0 && v[j][i] == 1){
                        ver[j][i] = {st, en};            
                    }
                    else if ( v[j][i] == 0){
                        cnt = 0;
                    }
                }
            }
        }

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout<<"{"<<ver[i][j].first<<","<<ver[i][j].second<<"} ";
        //     }
        //     cout<<endl;
        // }

        for(int i = 0; i< n; i++){
            for(int j = 0; j < n; j++){
                int cur = INT_MAX;
                if(v[i][j]){
                    cur = min(cur, min(i - ver[i][j].first + 1, ver[i][j].second - i + 1));

                    cur = min(cur, min(j - hor[i][j].first + 1, hor[i][j].second - j + 1));

                    ans= max(cur, ans);
                }


            }
        }
        return ans;
    }
};