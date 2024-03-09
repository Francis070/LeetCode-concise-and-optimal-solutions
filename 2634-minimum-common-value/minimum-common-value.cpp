class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // sort(begin(nums1), end(nums1));
        // sort(begin(nums2), end(nums2));

        if(nums1.size() < nums2.size()){
            for(int i : nums1){
                if(binary_search(begin(nums2), end(nums2), i))
                    return i;
            }
        }
        else{
            for(int i : nums2){
                if(binary_search(begin(nums1), end(nums1), i))
                    return i;
            }
        }
        
        return -1;
    }
};