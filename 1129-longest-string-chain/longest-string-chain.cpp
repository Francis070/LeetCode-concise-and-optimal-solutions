class Solution {
public:

    static bool comp(string &a, string &b){
        if(a.size() == b.size())
            return a < b;
        return a.size() < b.size();
    }

    bool is_pred(string & a, string &b){
        if(a.size() + 1 != b.size())
            return false;

        int i = 0, j = 0;
        int as = a.size(), bs = b.size();

        while(j < bs){
            if(a[i] == b[j]){
                i++;
            }
            j++;
        }
        if(i == as)
            return true;
        return false;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        vector<int> dp(n, 1);
        sort(words.begin(), words.end(), comp);
        
        for(int i = 1; i < n; i++){
            
            for(int j = i - 1; j >= 0; j--){
                if(is_pred(words[j], words[i])){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        int ans = *max_element(dp.begin(), dp.end());
        return ans;
    }
};