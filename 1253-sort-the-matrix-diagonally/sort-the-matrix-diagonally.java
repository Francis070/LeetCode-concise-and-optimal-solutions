class Solution {
    public int[][] diagonalSort(int[][] mat) {
        int n = mat.length, m = mat[0].length;

        for(int i = 0; i < n; i++){
            for( int j = 0; j < m; j++){
                if(i == 0 || j == 0){
                    ArrayList<Integer> t = new ArrayList<Integer>();
                    int x = i, y = j;
                    while(x < n && y < m){
                        t.add(mat[x++][y++]);
                    }

                    Collections.sort(t);
                    x = i; y = j;
                    for(int k  = 0; k < t.size(); k++){
                        mat[x++][y++] = t.get(k);
                    }
                }
                else{
                    continue;
                }
            }
        }

        return mat;
    }
}