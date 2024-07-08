class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v(n);

        for(int i = 0; i < n; i++)
            v[i] = i;

        int j = 0;
        while(v.size() > 1){
            int sz = v.size();

            int ty = (j + (k - 1))% sz;

            v[ty] = -1;
            for(int i = ty + 1; i < n; i++){
                v[i-1] = v[i];
            }

            j = ty;

            v.pop_back();


        }

        return (v[0] + 1);
    }
};