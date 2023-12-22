class Solution {
    public int maxScore(String s) {
        int n = s.length();

        int cnt_z = 0, cnt_o = 0;

        char[] ch = s.toCharArray();

        for(int i =0 ; i < n; i++){
            if(ch[i] == '1') cnt_o++;
        }
        int ans = 0;
        for(int i = 0; i< n-1; i++){
            if(ch[i] == '1') cnt_o--;
            else cnt_z++;
            ans = Math.max(ans, cnt_o + cnt_z);
        }

        return ans;
    }
}