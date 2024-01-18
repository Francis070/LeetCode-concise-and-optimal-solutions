class Solution {
public:
    int climbStairs(int n) {
        // vector<int> steps(n + 1, 0);
        // steps[0] = 1;
        // steps[1] = 1;
        // steps[2] = 2;
        int a = 1, b = 2, c = a + b;
        for(int i = 3; i <= n; i++){
            // steps[i] = steps[i-2] + steps[i-1];
            c = a + b;
            a = b;
            b = c;
        }

        if(n < 3){
            return (n == 1) ? a : b;
        }
        else
            return c;
    }
};