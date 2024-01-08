class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int n = stones.size();
        unordered_map<char, int> um;
        for(int i = 0 ; i < n; i++){
            um[stones[i]]++;
        }
        int ans = 0;
        for(int i = 0 ; i < jewels.size(); i++){
            ans += um[jewels[i]];
        }

        return ans;
    }
};