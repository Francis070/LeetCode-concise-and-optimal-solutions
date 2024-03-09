class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        sort(nums2.begin(), nums2.end());
        for(int j : nums1)
            st.insert(j);

        for(int j : nums2)
            if(st.find(j) != st.end())
                return j;
        
        return -1;
    }
};