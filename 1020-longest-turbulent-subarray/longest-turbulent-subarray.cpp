class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        int s = 0;
        for(int i = 1; i < n; i++){
            if(arr[i] == arr[i-1]){
                dp[i] = 1;
                s = 0;
            }
            else{
                if(s == 0){
                    if(arr[i]>arr[i-1])
                        s = -1;
                    else{
                        s = 1;
                    }
                    dp[i] = 2;
                }
                else{
                    if(arr[i] > arr[i-1] && s == 1){
                        s = -1;
                        dp[i] = dp[i-1] + 1;
                    }
                    else if(arr[i] < arr[i-1] && s == -1){
                        s = 1;
                        dp[i] = dp[i-1] + 1;
                    }
                    else{
                        dp[i] = 2;
                    }
                }
                // dp[i] = dp[i-1] + 1;
            }
        }
        // for(int i = 0; i< n; i++)
        //     cout<<dp[i]<<" ";
        int ans = 0;
        for(int x : dp)
            ans = max(ans, x);
        return ans;
    }
};