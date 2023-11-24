class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();

        sort(begin(piles), end(piles));
        int al = n-1, me = n - 2, bob = 0;
        int ans = 0;
        while(bob < me){
            ans += piles[me];
            bob++;
            al -= 2;
            me -= 2;
        }

        return ans;
    }
};