class Solution {
public:

    static bool comp(string a, string b){
        if(a.size() != b.size())
            return a.size() < b.size();
        
        return a < b;
    }

    bool isSub(string s, string t){   // function to find whether s is a sub-sequence of t and s.size() + 1 == t.size()
        int n1 = s.size(), n2 = t.size();

        if(n2 != n1 + 1)
            return false;

        int i = 0, j = 0;

        while(i < n2){
            if(t[i] == s[j]){
                j++;
            }
            i++;
        }

        if(j >= n1)
            return true;
        return false;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp); // sorting the words as we need to traverse from backwards and check the longest chain length.

        vector<int> dp(n, 0);  // in dp vector we are going to store the value of max chain length from pos i.
        dp[n-1] = 1;

        for(int i = n-2; i >= 0; i--){
            int mx = 1;
            for(int j = i + 1; j < n; j++){
                if(isSub(words[i], words[j]))
                    mx = max(mx, 1 + dp[j]);
            }
            dp[i] = mx;
        }

        int ans = 1;
        for(int i = 0; i < n; i++)  // finding the max value from all the indices and storing in ans.
            ans = max(ans, dp[i]);

        return ans;
    }
};