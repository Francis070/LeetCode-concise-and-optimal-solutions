#define ll long long
class Solution {
public:

    bool chk(vector<int> & freq){
        int mn = INT_MAX, mx = INT_MIN;
        for(int i =0; i< freq.size(); i++){
            if(freq[i] != 0){
                mn = min(mn, freq[i]);
                mx = max(mx, freq[i]);
            }
        }
        return (mx == mn);
    }

    ll rec(int previous_index, int current_index, string &s, int n, vector<vector<int>> & dp , vector<int> &freq){
        if(current_index >= n){
            if(chk( freq )){
                return 1;
            }
            else{
                return INT_MAX;
            }
        }

        if(dp[previous_index][current_index] < INT_MAX){
            return dp[previous_index][current_index];
        }
        
        ll cur = INT_MAX;
        freq[s[current_index] - 'a']++;
        if(chk(freq)){
            vector<int> nf(26, 0);
            cur = min(cur, 1 + rec(current_index + 1, current_index + 1, s, n, dp, nf));
        }
        cur = min(cur, rec(previous_index, current_index + 1 , s, n, dp, freq));


        return dp[previous_index][current_index] = cur;
    }

    int minimumSubstringsInPartition(string s) {
        // this is a question which can be solved using DP and not greedy as we cannot 
        // allocate the chars greedily to the substrsings. This will not give me a minimum answer
        // in all the cases.

        // partition dp

        int n = s.size();
        vector<int> freq(26, 0);

        vector<vector<int>> dp(n + 4, vector<int>(n + 4, INT_MAX));
        ll ans = rec(0, 0, s, n, dp, freq);

        return ans;
    }
};