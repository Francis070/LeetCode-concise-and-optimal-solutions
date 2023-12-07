class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        // string ans = "";
        // bool flg = false;
        // for(int i = n-1; i >= 0; i--){
        //     if(flg){
        //         ans = num[i] + ans;
        //     }
        //     else{
        //         if((num[i] - '0') % 2){
        //             ans += num[i];
        //             flg = true;
        //         }
        //     }
        // }
        int  i = n-1;
        while(i >= 0 && (num[i] - '0')%2 == 0){
            i--;
        }
        i++;
        string ans = num.substr(0 , i);

        return ans;
    }
};