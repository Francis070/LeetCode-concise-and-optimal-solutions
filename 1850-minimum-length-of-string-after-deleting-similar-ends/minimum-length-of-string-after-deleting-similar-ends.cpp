class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();

        int left = 0, right = n-1;
        char lastcur;
        int lcnt = 0, rcnt = 0;
        while(left <= right){
            lastcur = s[left];
            lcnt = 0; rcnt = 0;
            if(lastcur == s[right]){
                while(left <= right && s[left] == lastcur){
                    lcnt++;
                    left++;
                }

                while(right >= left && s[right] == lastcur){
                    rcnt++;
                    right--;
                }
            }
            else
                break;
        }

        if(left > right){
            if(lcnt > 1 || rcnt > 1)
                return 0;
            else{
                return 1;
            }
        }
        return right - left + 1;
    }
};