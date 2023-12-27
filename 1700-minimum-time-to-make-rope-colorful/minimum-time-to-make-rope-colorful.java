class Solution {
    public int minCost(String col, int[] nt) {
        int n = nt.length;
        int ans = 0;

        for(int i = 1; i < n; i++){
            if(col.charAt(i) == col.charAt(i-1)){
                int cur = nt[i-1];
                ans += nt[i-1];
                int j = i;
                while(j < n && (col.charAt(j) == col.charAt(j-1))){
                    ans += nt[j];
                    cur = Math.max(cur, nt[j]);
                    j++;
                }

                ans -= cur;
                i = j;
            }
        }

        return ans;
    }
}