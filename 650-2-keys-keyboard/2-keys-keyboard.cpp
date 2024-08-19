class Solution {
public:
    int minSteps(int n) {
        vector<int> v(n + 4,INT_MAX);

        v[0] = 0;
        v[1] = 0;
        v[2] = 2;
        v[3] = 3;

        for(int i = 4; i <= n; i++){
            for(int j = i -1; j >= 1; j--){
                if(i % j == 0){
                    // int cur = 1;
                    // int d = i/j - 1;
                    
                    v[i] = min(v[i], v[j] + (i/j));
                }
            }
        }

        return v[n];
    }
};