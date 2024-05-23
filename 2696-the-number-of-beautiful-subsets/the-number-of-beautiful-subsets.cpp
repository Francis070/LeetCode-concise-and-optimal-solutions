class Solution {
public:
    bool check(int x,int k,vector<int> &v){
        for(auto &i: v){
            if(abs(i-x)==k)return false;
        }
        return true;
    }
    void solve(int s,vector<int> &nums,int k,vector<int> &v,int &ans){
        if(s==nums.size()){
            ans++;
            return;
        }

        if(check(nums[s],k,v)){
            v.push_back(nums[s]);
            solve(s+1,nums,k,v,ans);
            v.pop_back();
        }
        solve(s+1,nums,k,v,ans);
    } 
    int beautifulSubsets(vector<int>& nums, int k) {
        int ans = -1;
        vector<int> v;
        solve(0,nums,k,v,ans);
        return ans;
    }
};