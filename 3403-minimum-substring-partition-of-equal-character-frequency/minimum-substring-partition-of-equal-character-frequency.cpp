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

    ll rec(int pre, int ind, string &s, int n, vector<vector<int>> & dp , vector<int> &freq
    // vector<vector<int>> & freq
    ){
        if(ind >= n){
            if(chk( freq )){
            // if(chk(s.substr(pre, ind - pre + 1))){
                return 1;
            }
            else{
                return INT_MAX;
            }
        }

        if(dp[pre][ind] < INT_MAX){
            return dp[pre][ind];
        }
        
        ll cur = INT_MAX;
        freq[s[ind] - 'a']++;
        // if(chk(s.substr(pre, ind - pre + 1))){
        if(chk(freq)){
            vector<int> nf(26, 0);
            cur = min(cur, 1 + rec(ind + 1, ind + 1, s, n, dp, nf));
        }
        cur = min(cur, rec(pre, ind + 1 , s, n, dp, freq));


        return dp[pre][ind] = cur;
    }

    int minimumSubstringsInPartition(string s) {
        // this is a question which can be solved using DP and not greedy as we cannot 
        // allocate the chars greedily to the substrsings. This will not give me a minimum answer
        // in all the cases.

        // partition dp

        int n = s.size();
        // vector<vector<int>> freq(26, vector<int>(n+4, 0));
        // for(int i =0; i< n; i++){
        //     freq[s[i] - 'a'][i]++;
        // }

        // for(int i =0; i < 26; i++){
        //     for(int j = 1; j < n+4; j++){
        //         freq[i][j] += freq[i][j-1];
        //     }
        // }

        // for(int i = 0; i < 26; i++){
        //     for(int j = 0; j < n+4; j++){
        //         cout<<freq[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int> freq(26, 0);

        vector<vector<int>> dp(n + 4, vector<int>(n + 4, INT_MAX));
        ll ans = rec(0, 0, s, n, dp, freq);

        return ans;
        // return 0;
    }
};