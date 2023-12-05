class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;

        int t = n, nxt = 0;
        while(t > 1){
            if(t % 2){
                t--;
                nxt++;

                nxt += t/2;
                ans += t/2;
                t = nxt;
                nxt = 0;
            }
            else{
                nxt += t/2;
                ans += t/2;
                t = nxt;
                nxt = 0;
            }
            
        }

        return ans;
    }
};