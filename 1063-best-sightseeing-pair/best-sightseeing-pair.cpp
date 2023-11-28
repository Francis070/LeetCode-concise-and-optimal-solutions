class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        vector<int> dp(n + 1, 0);
        int ans = INT_MIN;
        int cmax = values[0] - 1;
        for(int i = 1; i< n; i++){
            
            // for(int j = i - 1; j >= 0; j--){
            //     ans = max(ans, values[i] + values[j] - abs(i - j));
            // }
            ans = max(ans, values[i] + cmax);
            cmax = max(cmax - 1, values[i] - 1);
        }

        return ans;
    }
};