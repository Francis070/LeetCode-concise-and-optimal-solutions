class Solution {
public:
    int numSteps(string s) {
        int n = s.size();

        reverse(begin(s), end(s));
        int car = 0;
        int ans =0;
        for(int i = 0; i< n-1; i++){
            if(s[i] == '0'){
                if(car == 1){
                    ans += 2;
                    car = 1;
                }
                else{
                    ans += 1;
                }
            }
            else{
                if(car == 1){
                    ans += 1;
                    
                }
                else{
                    ans += 2;
                }
                car = 1;
            }
        }

        if(car == 1)
            ans++;

        return ans;
    }
};