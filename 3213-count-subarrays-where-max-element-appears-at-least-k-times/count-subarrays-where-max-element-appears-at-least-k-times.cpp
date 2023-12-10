class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> um;
        long long i = 0, j = 0, prev = -1;
        int mx = *max_element(nums.begin(), nums.end());
        
        long long ans = 0;
        
        while(i < n){
            um[nums[i]]++;
            
            if(um[mx] == k){
                
                while(um[mx] == k && j <= i){
                    um[nums[j++]]--;
                }
                j--;
                
                // calculate
                ans += (j - prev) + (n - i - 1) + ((j - prev - 1)*(n-i-1));
                
                prev = j;
                j++;
            }
            
            i++;
        }
        
        return ans;
    }
};