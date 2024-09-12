class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int a[26] = {0};
        for(char c : allowed){
            a[c - 'a'] = 1;
        }

        int ans = 0;
        for(string s : words){
            bool chk = false;
            for(char c : s){
                if(a[c - 'a'] == 0){
                    chk = true;
                    break;
                }
            }
            if(chk)
                continue;

            ans++;
        }

        return ans;
    }
};