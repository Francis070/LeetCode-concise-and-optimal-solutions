class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> vc(5, vector<int>(n, 0));
        int mod = 1e9 + 7;
        for( int i =0; i < 5; i++)
            vc[i][0] = 1;
        
        for(int i = 1; i < n; i++){
            // for a
            vc[0][i] = vc[1][i-1];

            // for e
            vc[1][i] = (vc[0][i-1] + vc[2][i-1]) % mod;

            // for i
            for(int j = 0; j< 5; j++){
                if(j != 2){
                    vc[2][i] = (vc[2][i] + vc[j][i-1]) % mod;
                }
            }

            // for o
            vc[3][i] = (vc[2][i-1] + vc[4][i-1])% mod;

            // for u
            vc[4][i] = vc[0][i-1];
        }

        int ans = 0;
        for(int i =0; i < 5; i++){
            ans = (ans + vc[i][n-1])%mod;
        }

        return ans;
    }
};