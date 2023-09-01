class Solution {
public:
    
    // int countBit(int n){
    //     int count = 0;
    //     while(n > 0){
    //         if(n & 1)
    //             count++;
    //         n >>= 1;
    //     }
    //     return count;
    // }
    
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        // ans.push_back(1);
        // ans.push_back(1);
        for(int i = 1; i <= n; i++){
            if(i%2){
                ans.push_back(ans[i/2] + 1);
            }
            else 
                ans.push_back(ans[i/2]);
        }
        return ans;
    }
};