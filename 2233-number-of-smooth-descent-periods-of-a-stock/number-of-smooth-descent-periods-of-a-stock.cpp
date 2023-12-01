class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long cur = 1;
        long long ans = 0;
        for(int i = 1; i < n; i++){
            if(prices[i - 1] - prices[i] == 1){
                cur++;
            }
            else{
                if(cur != 1)
                    ans += (cur * (cur + 1))/2;
                else
                    ans++;
                cur = 1;
            }
            // cout<<ans<<endl;
        }

        if(cur != 1)
            ans += (cur * (cur + 1))/2;
        else
            ans++;

        return ans;
    }
};