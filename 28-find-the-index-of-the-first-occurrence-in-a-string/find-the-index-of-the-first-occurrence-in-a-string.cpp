class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for(int i =0 ; i < n;  i++){
            int len = min(int(needle.size()), n-i);
            // string temp = haystack.substr(i, len);
            if(haystack[i] == needle[0] && len >= m){
                bool check = true;
                for(int j = 1; j < m; j++){
                    if(needle[j] != haystack[i + j]){
                        check = false;
                        break;
                    }
                }
                if(check)
                    return i;
            }
        }

        return -1;
    }
};