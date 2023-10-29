class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int t = minutesToTest/minutesToDie;

        return ( ceil( (1.0 * log2(buckets))/ (1.0 * log2(t + 1)) ) );
    }
};