class Solution {
    public int[][] intervalIntersection(int[][] fl, int[][] sl) {
        int n = fl.length, m = sl.length;

        int i = 0, j = 0;
        List<int[]> ans = new ArrayList<>();
        while(i < n && j < m){
            if(Math.max(fl[i][0], sl[j][0]) <= Math.min(fl[i][1], sl[j][1])){
                // ArrayList<Integer> cur = new ArrayList<>();
                ans.add(new int[]{Math.max(fl[i][0], sl[j][0]), Math.min(fl[i][1], sl[j][1])});
                
            }

            if(fl[i][1] <= sl[j][1])
                i++;
            else
                j++;
        }

        // return ans;
        return ans.toArray(new int[ans.size()][]);
    }
}