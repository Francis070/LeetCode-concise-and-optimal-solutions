class Solution {
    public int largestAltitude(int[] gain) {
        int n = gain.length;

        int ans = 0, run = 0;
        for(int i = 0; i < n; i++){
            run += gain[i];
            ans = Math.max(ans, run);
        }

        return ans;
    }
}