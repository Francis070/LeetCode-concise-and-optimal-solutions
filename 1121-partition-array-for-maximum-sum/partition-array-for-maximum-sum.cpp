class Solution {
public:

    int get_value(int ind, int prev, int n, int k, vector<int>& arr, vector<vector<int>> &dp){
        if(ind >= n){
            return 0;
        }

        if(dp[ind][prev] != -1)
            return dp[ind][prev];
        
        int ans = 0;
        //not take it in the k subarray.
        int cnt = ind - prev;
        int mx = 0;
        for(int i = prev; i < ind; i++)
            mx = max(arr[i], mx);
        int val = cnt * mx;
        ans = max(ans, val + get_value(ind + 1, ind, n, k, arr, dp));

        //take it in the k subarray but before checking.
        
        if(ind - prev + 1 <= k){
            //take and end
            cnt = ind - prev + 1;
            mx = 0;
            for(int i = prev; i <= ind; i++)
                mx = max(arr[i], mx);
            val = cnt * mx;
            ans = max(ans, val + get_value(ind + 1, ind + 1, n, k, arr, dp));

            //take and move
            ans = max(ans, get_value(ind + 1, prev, n, k, arr, dp));   
        }

        return dp[ind][prev] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int ans = get_value(0, 0, n, k, arr, dp);

        return ans;
    }
};