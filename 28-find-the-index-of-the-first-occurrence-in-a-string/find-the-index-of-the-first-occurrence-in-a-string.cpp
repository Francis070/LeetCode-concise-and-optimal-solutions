class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();

        for(int i =0 ; i < n;  i++){
            int len = min(int(needle.size()), n-i);
            string temp = haystack.substr(i, len);
            if(haystack[i] == needle[0] && needle == temp ){
                return i;
            }
        }

        return -1;
    }
};