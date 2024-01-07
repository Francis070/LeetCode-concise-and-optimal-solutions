class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        int c1 = n1/2, c2 = n2/2;
        
        set<int> s1, s2, s3;
        for(int i = 0; i < n1; i++){
            s1.insert(nums1[i]);
        }
        for(int i = 0; i < n2; i++){
            s2.insert(nums2[i]);
        }
        
        for(auto &x : s1)
            s3.insert(x);
        for(auto &x : s2)
            s3.insert(x);
        
        int mn = min(s1.size(), s2.size());
        int mx = max(s1.size(), s2.size());
        int tot = s3.size();
    
        int ln = 0;
        if(tot == mx){
            ln = min(mn, c1) + min(mx - min(mn, c1), c2);
        }
        else if (mn + mx == tot){
            ln = min(c1, mn) + min(c2, mx);
        }
        else{
            int com = mx + mn - tot;
            while(com > 0){
                if(mx >= mn){
                    mx--;
                }
                else{
                    mn--;
                }
                com--;
            }
            
            ln = min(mn, c1) + min(mx, c2);
        }
        
        return ln;
    }
};