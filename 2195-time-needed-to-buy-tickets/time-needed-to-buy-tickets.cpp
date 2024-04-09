class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();

        int ans = 0;
        int kv = tickets[k];
        ans += (k + kv);

        for(int i = 0; i < n; i++){
            if(i < k){
                ans += (min(tickets[i]-1, kv-1));
            }
            else if (i > k && kv > 1){
                ans += (min(tickets[i], kv-1));
            }
        }

        return ans;
    }
};