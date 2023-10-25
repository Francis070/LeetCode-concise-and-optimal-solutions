class Solution {
public:

    int rec(int n, int k){
        if(n == 1){
            return 0;
        }
        
        int cur;
        if(k % 2 == 1)
            cur = rec(n-1, (k + 1)/2);
        else
            cur = rec(n-1, k/2);
        
        int ans;
        if(cur == 0){
            if(k%2 == 0)
                ans = 1;
            else
                ans = 0;
        }
        else{
            if(k%2 == 0)
                ans = 0;
            else
                ans = 1;
        }

        return ans;
    }

    int kthGrammar(int n, int k) {
        int ans = rec(n, k);
        return ans;
    }
};