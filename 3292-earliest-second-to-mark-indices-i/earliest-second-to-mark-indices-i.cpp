#define ll long long

class Solution {
public:

    bool chk(int mid, vector<int>& nums, vector<int>& ci){
        int n = nums.size();
        unordered_map<int, int> um;
        int mx = INT_MIN, mn = INT_MAX;
        for(int i = 1; i <= mid; i++){
            // st.insert(i);
            um[ci[i-1]] = i;
            mx = max(mx, ci[i-1]);
            mn = min(mn, ci[i-1]);
        }

        if(um.size() != n || mn != 1 || mx != n)
            return false;
        
        map<int, int> mxi;
        for(auto & x : um){
            mxi[x.second] = nums[x.first - 1];
        }
        int used = 0;
        for(auto & x : mxi){
            if((x.first - used) >= (x.second + 1)){
                used += x.second + 1;
                continue;
            }
            else
                return false;
        }
        return true;
    }

    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& ci) {
        ll low = 0, high = ci.size();

        for(int i : nums){
            low += i;
        }
        int ans = -1;
        while(low <= high){
            ll mid = low + (high - low)/2;

            if(chk(mid, nums, ci)){
                ans = mid;
                high = mid -1;
            }
            else
                low = mid + 1;
        }

        return ans;
    }
};