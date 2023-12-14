class Solution {
    public boolean canPlaceFlowers(int[] fb, int k) {
        int n = fb.length;

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(i == 0){
                if((n == 1 || fb[i + 1] == 0) && fb[i] == 0){
                    cnt++;
                    fb[i] = 1;
                } 
            }
            else if (i == n-1){
                if(fb[i - 1] == 0 && fb[i] == 0){
                    cnt++;
                }
            }
            else{
                if((i - 1 >= 0) && (i + 1 < n) && (fb[i - 1] == 0) && (fb[i] == 0) && (fb[i + 1] == 0)){
                    fb[i] = 1;
                    cnt++;
                }
            }
        }

        return cnt >= k;
    }
}