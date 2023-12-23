class Solution {
public:

    bool check(int mid, vector<int> & nums, int p){
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            if(nums[i+1] - nums[i] <= mid){
                res++;
                i++;
            }
        }

        if(res < p)
            return false;
        return true;
    }

    int minimizeMax(vector<int>& nums, int p) {
        if(p == 0)
            return 0;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int low = INT_MAX, high = nums[n-1] - nums[0];
        for(int i = 1; i < n; i++){
            low = min(low, nums[i] - nums[i-1]);
        }
        // cout<<low<<" "<<high;
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;

            if(check(mid, nums, p)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};