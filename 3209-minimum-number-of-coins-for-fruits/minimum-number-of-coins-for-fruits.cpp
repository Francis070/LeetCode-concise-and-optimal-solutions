class Solution {
public:
    int dp[1005][1005];
    int rec(int ind, int ff, int n, vector<int> & price){
        if(ind >= n)
            return 0;
        
        if(dp[ind][ff] != -1)
            return dp[ind][ff];
        
        int cur = INT_MAX;
        if(ff == 0){
            cur =  price[ind] + rec(ind + 1, ind + 1, n, price);
        }
        else{
            int buy = price[ind] + rec(ind + 1,  ind + 1, n, price);
            int notbuy = rec(ind + 1, ff - 1, n, price);
            
            cur = min(buy, notbuy);
        }
        
        return dp[ind][ff] = cur;
    }
    
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        
        memset(dp, -1, sizeof(dp));
        
        int ans = rec(0, 0, n, prices);
        
        return ans;
    }
};