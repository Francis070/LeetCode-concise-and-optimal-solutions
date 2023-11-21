class Solution {
public:

    bool check(int mid, int d, vector<int>& wt){
        int res = 1;
        int n = wt.size();
        int rw = 0;

        // cout<<mid<<" "<<d<<endl;
        for(int i = 0; i < n; i++){
            if((rw + wt[i]) <= mid){
                rw += wt[i];
            }
            else{
                if(wt[i] > mid)
                    return false;

                res++;
                rw = wt[i];
            }
        }
        // cout<<mid<<" "<<d<<" "<<res<<endl;
        return (res <= d);
    }

    int shipWithinDays(vector<int>& wt, int d) {
        int low = *min_element(wt.begin(), wt.end());

        int high = 0;

        for(int x : wt)
            high += x;
        int ans = high;
        // cout<<low<<" "<<high<<endl;
        while(low < high){

            int mid = low + (high - low)/2;

            if(check(mid, d, wt)){
                ans = min(ans, mid);
                high = mid;
            }
            else{
                low = mid + 1;
            }

        }

        return ans;
    }
};