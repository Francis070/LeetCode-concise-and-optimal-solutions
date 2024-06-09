#define ll long long

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        ll n = nums.size();

        map<ll, vector<ll>> mp;

        vector<ll> pre(n, 0);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++){
            pre[i] = pre[i-1] + nums[i];
        }
        int ans = 0;

        // for(int i =0 ; i < n; i++){
        //     if(pre[i] % k == 0)
        //         ans++;
        //     for(int j = i-1; j >= 0; j--){
        //         if((pre[i] - pre[j])% k == 0){
        //             ans++;
        //         }
        //     }
        // }

        // return ans;

        for(int i =0; i < n; i++){
            // if(nums[i] % k == 0){
            //     if( (pre[i]%k != 0 && mp[pre[i]%k].size() == 0) || (mp[pre[i]%k].size() > 0 && mp[pre[i]%k].back() != (i - 1)))
            //         ans++;
            // }
            mp[((pre[i]%k) + k) % k].push_back(i);
        }
        
        for(auto & x : mp){
            // cout<<x.first<<"->";
            // for(auto & y : x.second){
            //     cout<<y<<" ";
            // }
            // cout<<endl;
            int sz = x.second.size();
            if(x.first != 0){
                
                ans += (sz * (sz - 1))/2;
            }
            else{
                ans += (sz * (sz + 1))/2;
            }
        }

        return ans;
    }
};