class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        int temp = x;

        while(temp){
            if( (res * 10) + (temp%10) > INT_MAX ||  (res * 10) + (temp%10) < INT_MIN)
                return 0;

            res = (res * 10) + (temp%10);
            temp /= 10;
        }

        return res;
    }
};