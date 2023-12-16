class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        map<int, int> m;

        for(int i =0; i < n; i++){
            if(m.size() == 0){
                m[nums[i]] = nums[i];
            }
            else{
                auto x = m.lower_bound(nums[i]);
                if(x == m.end()){
                    x = prev(x);
                }
                // cout<<i<<" "<<nums[i]<<" "<<x->first<<" "<<x->second<<endl;
                if(abs(x->first - nums[i]) <= k && abs(x->second - nums[i]) <= k){
                    if(nums[i] < x->first){
                        int y = x->second;
                        m.erase(x);
                        m[nums[i]] = y;
                    }
                    else{
                        x->second = max(x->second, nums[i]);
                    }
                }
                else if(x != m.begin() && (abs(prev(x)->first - nums[i]) <= k && abs(prev(x)->second - nums[i]) <= k)){
                    x = prev(x);
                    if(nums[i] < x->first){
                        int y = x->second;
                        m.erase(x);
                        m[nums[i]] = y;
                    }
                    else{
                        x->second = max(x->second, nums[i]);
                    }
                }
                else{
                    m[nums[i]] = nums[i];
                }
            }
        }

        for(auto &x : m){
            cout<<x.first<<" "<<x.second<<endl;
        }

        return m.size();
    }
};