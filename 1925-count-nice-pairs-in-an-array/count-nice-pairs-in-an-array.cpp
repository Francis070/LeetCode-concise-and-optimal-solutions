class Solution {
public:
    int mod = 1e9 + 7;
    long long calc(int r){
        string s = to_string(r);
        reverse(s.begin(), s.end());
        long long rev = stoi(s);

        return (r - rev)%mod;
    }

    int countNicePairs(vector<int>& nums) {
        int n = nums.size();

        unordered_map<long long, long long> um;

        for(int i = 0; i < n; i++){
            long long val = calc(nums[i]);
            um[val]++;
        }

        // for(auto &x : um){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }

        long long ans = 0;
        for(auto & x : um){
            ans = (ans + ((x.second * (x.second - 1)))/2 )%mod;
        }

        return ans;
    }
};