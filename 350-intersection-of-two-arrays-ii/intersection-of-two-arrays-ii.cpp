class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> um;
        for(int x : nums1){
            um[x]++;
        }
        vector<int> ans;
        for(int x : nums2){
            if(um.count(x)){
                ans.push_back(x);
                if(um[x] == 1){
                    um.erase(x);
                }
                else{
                    um[x]--;
                }
            }
        }

        return ans;
    }
};