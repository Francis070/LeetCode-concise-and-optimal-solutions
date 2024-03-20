#define ll  long long

class Solution {
public:
    long long coloredCells(int n) {
        ll edges = 4;
        ll common_cell = 0;
        ll prev = 1;
        ll i = 2;
        ll cur = prev;
        while(i <= n){
            cur = prev + edges - common_cell;
            i++;
            prev = cur;
            edges += 8;
            common_cell += 4;
        }   

        return prev;
    }
};