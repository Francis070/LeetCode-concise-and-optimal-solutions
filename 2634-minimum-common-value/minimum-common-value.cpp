class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // sort(begin(nums1), end(nums1));
        // sort(begin(nums2), end(nums2));

        for(int i : nums1){
            if(binary_search(begin(nums2), end(nums2), i))
                return i;
        }

        return -1;
    }
};