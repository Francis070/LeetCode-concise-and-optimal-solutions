class Solution {
public:
    int longestString(int x, int y, int z) {
        int mn = min(x, y);
        int mx = max(x, y);
        int ans = 0;
        if(mx > mn){
            ans = (2 * mn) + 1;
        }
        else
            ans = 2*mn;

        return 2*(ans + z);
    }
};