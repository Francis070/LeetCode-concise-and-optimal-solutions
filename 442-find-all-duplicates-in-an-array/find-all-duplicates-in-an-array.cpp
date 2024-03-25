class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1){
                while(nums[nums[i] - 1] != nums[i]){
                    swap(nums[i], nums[nums[i] - 1]);
                    // if(nums[i]== nums[nums[i] - 1])
                    //     break;
                }
                if(nums[i] == nums[nums[i] - 1] && i != nums[i] - 1)
                    st.insert(nums[i]);
            }
        }

        vector<int> ans;
        for(auto x : st)    
            ans.push_back(x);
        return ans;
    }
};