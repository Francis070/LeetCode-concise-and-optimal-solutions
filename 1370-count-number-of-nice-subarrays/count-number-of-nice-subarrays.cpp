class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> l, r;
        int cnt = 1;
        for(int i = 0; i < n; i ++){
            if(nums[i] % 2 == 1){
                l.push_back(cnt);
                cnt = 1;
            }
            else{
                cnt++;
            }
        }
        cnt = 1;
        for(int i = n-1; i >= 0; i--){
            if(nums[i] % 2 == 1){
                r.push_back(cnt);
                cnt = 1;
            }
            else{
                cnt++;
            }
        }

        reverse(begin(r), end(r));

        // for(int i : l)
        //     cout<<i<<" ";
        // cout<<endl;
        // for(int j : r)
        //     cout<<j<<" ";


        if(l.size() < k){
            return 0;
        }
        int ans = 0;
        for(int i = k - 1; i< l.size(); i++){
            ans += (r[i] * l[i - k + 1]);
        }

        return ans;
    }
};