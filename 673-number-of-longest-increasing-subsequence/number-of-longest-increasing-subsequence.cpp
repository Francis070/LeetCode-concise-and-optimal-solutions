class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n, 1), len(n, 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j] && cnt[j] + 1  > cnt[i]){
                    cnt[i] = cnt[j] + 1;
                    len[i] = len[j];
                    
                }
                else if(nums[j] < nums[i] && cnt[j] + 1 == cnt[i]){
                    cnt[i] = cnt[j] + 1;
                    len[i] += len[j];
                }
            }
        }
        int res = 0, ans = INT_MIN;
        for(int x : cnt)
            ans = max(ans, x);
        for(int i = 0; i < n; i++){
            // cout<<cnt[i]<<" "<<len[i]<<endl;
            if(cnt[i] == ans)
                res += len[i];
        }

        return res;
    }
};