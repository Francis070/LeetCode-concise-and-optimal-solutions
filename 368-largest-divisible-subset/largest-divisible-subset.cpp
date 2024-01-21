class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<int> cnt(n, 1), prev(n, -1);

        // vector<vector<int>> v(n);
        // for(int i = 0; i < n; i++){
        //     v[i].push_back(nums[i]);
        // }
        // cnt[0] = 1;
        for(int i = 1; i < n; i++){
            for(int j =0; j < i ; j++){
                if(nums[i] % nums[j] == 0 && 1 + cnt[j] > cnt[i]){
                    cnt[i] = max(cnt[i], cnt[j] + 1);
                    // v[j].push_back(nums[i]);
                    // v[i].push_back(nums[j]);
                    prev[i] = j;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n ; i++)
            ans = max(ans, cnt[i]);
        cout<<ans;
        // for(int i = 0; i < n; i++){
        //     cout<<cnt[i]<<" "<<prev[i]<<endl;
        // }
        vector<int> res;

        for(int i = n-1; i >= 0; i--){
            if(cnt[i] == ans){
                res.push_back(nums[i]);
                int j= i;
                while(prev[j] != -1){
                    j = prev[j];
                    res.push_back(nums[j]);
                }
                break;
            }
        }
        return res;
    }
};


// 2 5 4 3 6

// sorted
// 2 3 4 5 6

// if 2 is there then all the numbers except 1 should be even