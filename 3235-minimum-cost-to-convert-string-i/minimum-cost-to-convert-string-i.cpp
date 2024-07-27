#define ll long long 

class Solution {
public:
    long long minimumCost(string src, string tar, vector<char>& ori, vector<char>& chan, vector<int>& cost) {
        vector<vector<ll>> v(26, vector<ll>(26, LONG_MAX));

        for(int i = 0; i < 26; i++){
            v[i][i] = 0;
        }
        int n = ori.size();
        for(int i = 0; i < n; i++){
            int x = ori[i] - 'a';
            int y = chan[i] - 'a';

            v[x][y] = min(v[x][y], static_cast<ll>(cost[i]));
        }

        for(int via = 0; via < 26; via++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    if(v[i][via] != LONG_MAX && v[via][j] != LONG_MAX)
                        v[i][j] = min(v[i][j], v[i][via] + v[via][j]);
                }
            }
        }

        // for(int i = 0; i < 26; i++){
        //     for(int j = 0; j < 26; j++){
        //         cout<<v[i][j];
        //     }
        //     cout<<endl;
        // }

        int m = src.size();
        ll ans = 0;
        for(int i =0;i < m; i++){
            if(src[i] != tar[i]){
                if(v[src[i] - 'a'][tar[i] - 'a'] >= LONG_MAX){
                    return -1;
                }
                else{
                    ans += v[src[i] - 'a'][tar[i] - 'a'];
                }
            }
        }

        return ans;
    }
};