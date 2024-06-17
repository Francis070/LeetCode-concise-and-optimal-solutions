class Solution {
public:

    bool check(int a, int b){
        int c = b - (a * a);

        int d = sqrt(c);

        if((d * d) == c){
            return true;
        }

        return false;
    }

    bool judgeSquareSum(int c) {
        int sq = sqrt(c);

        if(c == 0)
            return true;

        for(int i = 1; i <= sq; i++){
            if(check(i, c)){
                return true;
            }
        }

        return false;
        
    }
};