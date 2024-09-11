class Solution {
public:

    int minBitFlips(int start, int goal) {
        int ans = 0;
        while(start && goal){

            if((start & 1) != (goal & 1)){
                ans++;
            }
            start>>=1;
            goal>>=1;
        }

        if(start > 0 || goal > 0){
            while(start){
                if(start & 1)
                    ans ++;
                start>>= 1;
            }
            while(goal){
                if(goal & 1)
                    ans++;
                goal >>=1;
            }
        }

        return ans;
    }
};