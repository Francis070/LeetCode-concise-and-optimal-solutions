#define ll long long

class Solution {
public:

    ll get_sum(int low, int mid){
        int n = mid - low + 1;
        ll res = ((n) * ((2 * low) + (n-1)) )/2;

        return res;
    }

    int pivotInteger(int n) {
        int low = 1, high = n;

        // ll sum = (n * (n + 1))/2;
        // ll ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;

            ll leftsum = get_sum(1, mid);
            ll rightsum = get_sum(mid, n);

            if(leftsum == rightsum){
                return mid;
            }

            if(leftsum > rightsum){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return -1;
    }
};