class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        int s =  fb.size();
        int cnt = 0;
        for(int i = 0; i < s; i++){
            if( i== 0 && fb[i] == 0){
                if((i + 1 < s && fb[i + 1] == 0) || (i == s-1)){
                    cnt++;
                    if(i + 1 < s)
                        fb[i] = 1;
                }
            }
            else if(i == s - 1 && fb[i] == 0){
                if((i - 1 >= 0 && fb[i - 1] == 0) || (i == 0)){
                    cnt++;
                    if(i - 1 >= 0)
                        fb[i] = 1;
                }
            }
            else{
                if(fb[i] == 0 && fb[i + 1] == 0 && fb[i -1 ] == 0){
                    fb[i] = 1;
                    cnt++;
                }
            }
        }

        return cnt >= n;

    }
};