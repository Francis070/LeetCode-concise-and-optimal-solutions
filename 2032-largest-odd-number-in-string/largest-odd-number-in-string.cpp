class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        
        int  i = n-1;
        while(i >= 0 && (num[i] - '0')%2 == 0){
            i--;
        }
        i++;
        
        num = num.substr(0 , i);

        return num;
    }
};