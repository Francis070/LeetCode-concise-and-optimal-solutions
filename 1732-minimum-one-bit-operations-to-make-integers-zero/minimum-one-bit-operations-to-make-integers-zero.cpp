class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0){
            return 0;
        }

        int k = 0, t = n;
        while(t > 0){
            t >>= 1;
            k++;
        }

        int curr = pow(2, k-1);

        return (pow(2, k) - 1 - minimumOneBitOperations(n ^ curr));
    }
};