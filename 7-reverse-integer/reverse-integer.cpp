class Solution { 
public: 
    int reverse(int x) { 
        int t =abs(x); 
        long long r=0; 
        // long long r
        while(t){ 
            if(r<INT_MAX and r>INT_MIN){ 
               int re =t%10;

               
               r= r*10+re; 
               if(r > (pow(2, 31) - 1) || r < (-1 * (pow(2, 31) - 1))) 
                    return 0;
                 t=t/10; 
        } 
        } 
        if(x<0){ 
           r= -1*r; 
        } 
        return r; 
    } 
};