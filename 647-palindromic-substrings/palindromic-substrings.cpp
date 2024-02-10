class Solution {
public:

    int count_substring(string &s, int value){
        int count = 0;
        int size = s.size();

        for(int i = 0; i < size; i++){
            int temp_cnt = 0;
            int left = i - 1, right = i + value;
            while(left >= 0 && right < size && s[left] == s[right]){
                temp_cnt++;
                left--;
                right++;
            }
            count += temp_cnt;
        }
    

        return count;
    }

    int countSubstrings(string s) {
        int size = s.size();
        int ans = size;
        // checking for odd length substring

        ans = ans + count_substring(s, 1);

        // checking for even length substring

        ans = ans + count_substring(s, 0);

        return ans;
    }
};

/*DRY RUN

case 1 - "abcddcab"

size = 8

*/

/*
edge case

odd length sub string

even length sub string


case 1 - "abcddcab"

ans = 8 + 1 + 1 = 10

case 2 - "ertreb"

ans = 6 + 1 + 1 = 8

case 3 - "abcabc"

ans = 6



*/