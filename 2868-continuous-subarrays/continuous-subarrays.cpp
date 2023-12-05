class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();

        multiset<int> ms;
        long long ans = n;
        int i = 0, j = 0;

        while(i < n){
            ms.insert(nums[i]);
            int mx = *(ms.rbegin());
            int mn = *(ms.begin());

            while((mx - mn) > 2  && j < i){
                ms.erase(ms.find(nums[j]));
                mx = *(ms.rbegin());
                mn = *(ms.begin());
                j++;
            }
            ans += i - j;

            i++;
        }

        return ans;
    }
};