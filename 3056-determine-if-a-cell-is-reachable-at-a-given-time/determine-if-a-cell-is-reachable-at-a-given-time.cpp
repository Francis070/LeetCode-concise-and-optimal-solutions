class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x = abs(sx - fx), y = abs(sy - fy);

        if((sx != fx || sy != fy) && t >= max(x, y)){
            return true;
        }
        if(sx == fx && sy == fy){
            if(t == 1)
                return false;
            else
                return true;
        }
        return false;
    }
};