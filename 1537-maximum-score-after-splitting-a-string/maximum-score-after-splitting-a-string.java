class Solution {
    public int maxScore(String s) {
        int n = s.length();

        int cnt_z = 0, cnt_o = 0;

        int ans = Integer.MIN_VALUE;

        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == '1')
                cnt_o++; 
            else
                cnt_z++;

            if(i != s.length() - 1){
                ans = Math.max(ans, cnt_z - cnt_o);
            }
        }

        return ans + cnt_o;
    }
}