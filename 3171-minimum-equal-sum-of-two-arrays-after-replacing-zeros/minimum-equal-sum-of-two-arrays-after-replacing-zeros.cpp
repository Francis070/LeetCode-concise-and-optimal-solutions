class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        long long s1 = 0, s2 = 0, c1 = 0, c2 = 0;
        
        for(int i =0; i < n; i++){
            if(nums1[i] == 0)
                c1++;
            else{
                s1 += nums1[i];
            }
        }
        for(int i =0; i < m; i++){
            if(nums2[i] == 0)
                c2++;
            else{
                s2 += nums2[i];
            }
        }
        
        if(c1 == 0 && s1 < (s2 + c2))
            return -1;
        if(c2 == 0 && s2 < (s1 + c1))
            return -1;

        return max(s1 + c1, s2 + c2);
    }
};