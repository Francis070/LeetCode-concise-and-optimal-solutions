class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1, high = num/2;

        if(num == 1)
            return 1;

        while(low < high){
            int mid = low + (high - low)/2;

            if(mid >= (num/mid)){
                high = mid;
            }
            else
                low = mid + 1;
        }
        cout<<high;
        if(((high) == num/high) && (num%high) == 0)
            return true;
        return false;
    }
};