class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();

        int i = 0, j = n-1;
        int cur = 0;
        int ans = 0;
        while(i < j){
            if(s[i] == '[')
                cur++;
            else
                cur--;

            if(cur < 0){
                ans++;
                while(s[j] != '[' && j >= 0)
                    j--;
                swap(s[i], s[j]);
                cur = 1;
            }
            i++;
        }

        return ans;
    }

};