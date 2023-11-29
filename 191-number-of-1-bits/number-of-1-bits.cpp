class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t temp = n;
        int ans = 0;
        
        while(temp > 0){
            if(temp & 1)
                ans++;
            temp >>=1;
        }

        return ans;
    }
};