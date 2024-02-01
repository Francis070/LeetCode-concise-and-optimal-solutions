class Solution {
    public int finalValueAfterOperations(String[] opn) {
        int n = opn.length;
        int x = 0;
        // System.out.println(n);
        for(int i =0; i < n; i++){
            if(opn[i].equals("++X") || opn[i].equals("X++") ){
                x++;
                // System.out.println(x);
            }
            else{
                x--;
            }
        }

        return x;
    }
}