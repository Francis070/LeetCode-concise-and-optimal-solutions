class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<int> v(amount + 1, 1e8);
        for(int i =0; i< n; i++){
            if(coins[i] <= amount){
                v[coins[i]] = 1;
            }
        }
        v[0] = 0;
        for(int i = 1;  i <= amount; i++){
            for(int j = 0; j < n; j++){
                if(coins[j] <= i && v[i - coins[j]] != 1e8)
                    v[i] = min(v[i], 1 + v[i - coins[j]]);
            }
         
        }
        if(v[amount] == 1e8)
            return -1;
        return v[amount];
    }
};