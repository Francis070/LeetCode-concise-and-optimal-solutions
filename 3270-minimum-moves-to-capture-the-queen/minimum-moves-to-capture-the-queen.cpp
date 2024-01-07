class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        
        // uth ki chal

        bool hathi_mila = false, queen_mili= false;

        int x = c, y = d;
        while(x >= 1 && y >= 1){
            if(x == a && y == b){
                hathi_mila = true;
            }
            if(x == e && y == f){
                queen_mili = true;
            }
            if(hathi_mila == true || queen_mili == true)
                break;
            x--; y--;
        }
        if(queen_mili)
            return 1;
        
        hathi_mila = false;
        x = c; y = d;
        while(x >= 1 && y <= 8){
            if(x == a && y == b){
                hathi_mila = true;
            }
            if(x == e && y == f){
                queen_mili = true;
            }
            if(hathi_mila == true || queen_mili == true)
                break;
            x--; y++;
        }
        if(queen_mili)
            return 1;
        hathi_mila = false;
        x = c; y = d;
        while(x <= 8 && y <= 8){
            if(x == a && y == b){
                hathi_mila = true;
            }
            if(x == e && y == f){
                queen_mili = true;
            }
            if(hathi_mila == true || queen_mili == true)
                break;
            x++; y++;
        }
        if(queen_mili)
            return 1;
        hathi_mila = false;
         x = c; y = d;
        while(x <= 8 && y >= 1){
            if(x == a && y == b){
                hathi_mila = true;
            }
            if(x == e && y == f){
                queen_mili = true;
            }
            if(hathi_mila == true || queen_mili == true)
                break;
            x++; y--;
        }
        if(queen_mili)
            return 1;
        
        
        //hathi ki chal
        
        bool uth_mila = false; queen_mili= false;

        x = a; y = b;
        while(x >= 1){
            if(x == c && y == d){
                uth_mila = true;
            }
            if(x == e && y == f){
                queen_mili = true;
            }
            if(uth_mila == true || queen_mili == true)
                break;
            x--;
        }
        if(queen_mili )
            return 1;
        x = a; y = b;
        uth_mila = false;
        while(y <= 8){
            if(x == c && y == d){
                uth_mila = true;
            }
            if(x == e && y == f){
                queen_mili = true;
            }
            if(uth_mila == true || queen_mili == true)
                break;
            y++;
        }
        if(queen_mili)
            return 1;
        x = a; y = b;
        uth_mila = false;
        while(x <= 8 ){
            if(x == c && y == d){
                uth_mila = true;
            }
            if(x == e && y == f){
                queen_mili = true;
            }
            if(uth_mila == true || queen_mili == true)
                break;
            x++;
        }
        if(queen_mili)
            return 1;
        uth_mila = false;
     	x = a; y = b;
        while(y >= 1){
            if(x == c && y == d){
                uth_mila = true;
            }
            if(x == e && y == f){
                queen_mili = true;
            }
            if(uth_mila == true || queen_mili == true)
                break;
            y--;
        }
        if(queen_mili)
            return 1;
            
        
        return 2;
    }
};