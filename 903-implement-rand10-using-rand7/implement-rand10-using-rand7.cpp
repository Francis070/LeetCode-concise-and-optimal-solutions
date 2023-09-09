// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int x = rand7(), y = rand7();
        int exp = (x - 1)*7 + y;
        // return exp;
        while(exp > 10){
            x = rand7(), y = rand7();
            exp = (x - 1)*7 + y;
        }
        return exp;
    }
};