class Solution {
public:
    
    int findComplement(int num) {
        int ans = 0;
        int cnt = 0;

        while(num > 0){
            if((num & 1) == 0){
                // cout<<num<<endl;
                ans += pow(2, cnt);
            }

            num >>= 1;
            cnt++;
        }

        return ans;
    }
};