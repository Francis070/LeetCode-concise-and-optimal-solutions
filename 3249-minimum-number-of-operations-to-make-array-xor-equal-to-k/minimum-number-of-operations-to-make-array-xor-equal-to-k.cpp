class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n= nums.size();
        
        vector<vector<int>> v(n, vector<int>(33, 0));
        
        for(int i = 0; i < n; i++){
            int j = 0;
            int t = nums[i];
            while(t){
                if(t & 1)
                    v[i][j] = 1;
                j++;
                t>>=1;
            }
        }
        
        vector<int> re(33, 0), we(33, 0);
        
        for(int i = 0; i < 33; i++){
            int c = 0;
            for(int j = 0; j < n; j++){
                if(v[j][i])
                    c++;
            }
            we[i] = c;
        }
        
        int e = k;
        int y = 0;
        while(e){
            if(e & 1)
                re[y] = 1;
            y++;
            e>>= 1;
        }
        
        int ans = 0;
        for(int i =0; i < 33; i++){
            if((re[i] == 1 && we[i]%2 == 0) || (re[i] == 0 && we[i]%2 == 1)){
                ans++;
            }
        }
        
        return ans;
    }
};