class Pair implements Comparable<Pair>{
    public int first, second;

    public Pair(int k, int v){
        this.first = k;
        this.second = v;
    }

    public int getKey(){
        return this.first;
    }

    public int getValue(){
        return this.second;
    }

    @Override
    public int compareTo(Pair other) {
        // Comparison logic to sort pairs in TreeSet
        if (this.first != other.first) {
            return Integer.compare(this.first, other.first);
        } else {
            return Integer.compare(this.second, other.second);
        }
    }
}

class Solution {
    public boolean isPathCrossing(String path) {
        // TreeSet<Map.Entry<Integer, Integer>> um = new TreeSet<>();
        TreeSet<Pair> um = new TreeSet<>();

        int x = 0, y = 0;
        um.add(new Pair(x, y));

        for(char c : path.toCharArray()){
            if(c == 'N') y++;
            else if(c == 'S') y--;
            else if(c == 'W') x--;
            else x++;

            if(um.contains(new Pair(x, y)))
                return true;
            
            um.add(new Pair(x, y));
        }
        return false;
    }
}