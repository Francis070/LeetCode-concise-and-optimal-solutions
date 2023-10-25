class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if(m > n)
            return -1;

        for(int i =0 ; i <= n-m;  i++){
            if(haystack[i] == needle[0]){
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