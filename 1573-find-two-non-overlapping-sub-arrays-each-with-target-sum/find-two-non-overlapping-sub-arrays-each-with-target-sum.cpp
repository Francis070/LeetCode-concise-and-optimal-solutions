class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int j = 0, n = arr.size();
    int sum = 0;
    vector<int> dp(n, INT_MAX);
    int ans = INT_MAX, minlen = INT_MAX;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        
        while(sum > target){
            sum -= arr[j];
            j++;
        }
        if(sum == target){
            if(j-1 > 0 && dp[j-1] < INT_MAX){
                ans = min(ans, dp[j-1] + i-j + 1);
            }
            minlen = min(minlen, i - j + 1);
        }
        
        dp[i] = min(dp[i], minlen);
    }
    
    if(ans == INT_MAX)
        return -1;
    return ans;
    }
};