class Solution {
    public long maximumHappinessSum(int[] hp, int k) {
        int n = hp.length;

        long ans = 0;
        // Arrays.sort(hp, Collections.reverseOrder());
        Arrays.sort(hp);

        for(int i =n-1; i >= (n - k); i--){
            ans += Math.max(hp[i] - (n-i-1), 0);
        }

        return ans;
    }
}