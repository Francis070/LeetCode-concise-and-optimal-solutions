class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        set<int> prev;
        int ans = INT_MAX;
        for(int i =0; i < n; i++){
            set<int> next;
            for(int e : prev){
                next.insert(e & nums[i]);
            }

            next.insert(nums[i]);

            for(int er : next)
                ans = min(ans, abs(k - er));

            prev = next;
        }

        return ans;
    }
};