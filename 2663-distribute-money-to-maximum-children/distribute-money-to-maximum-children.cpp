class Solution {
public:

    bool check(int m, int c, int mon){
        int val = mon - (m * 8);
        // cout<<val<<" "<<(c - m)<<endl;
        if(val < (c - m))
            return false;

        if(((val == 4) && ((c - m) == 1)) || ((c - m) == 0 && val > 0))
            return false;

        return true;
    }

    int distMoney(int money, int children) {
        int low = 1, high = children;

        if(money < children)
            return -1;

        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(check(mid, children, money)){
                // cout<<mid<<endl;
                ans = mid;
                low = mid + 1;
            }
            else{
                // cout<<mid<<endl;
                high = mid - 1;
            }
        }

        return ans;
    }
};