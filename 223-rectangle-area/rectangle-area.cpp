class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a1 = (ax2 - ax1) * (ay2 - ay1);
        int a2 = (bx2 - bx1) * (by2 - by1);
        // cout<<a1 + a2;

        if(by1 >= ay2 || ay1 >= by2 || bx1 >= ax2 || ax1 >= bx2)
            return a1 + a2;

        int l, b;
        l = min(by2, ay2) - max(ay1, by1);
        b = min(bx2, ax2) - max(bx1, ax1);

        return a1 + a2 - (l * b);
    }
};