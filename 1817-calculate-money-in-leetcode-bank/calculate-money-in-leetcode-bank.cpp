class Solution {
public:
    int totalMoney(int n) {
        vector<int> v(7, 0);

        for(int i = 0; i < 7; i++){
            v[i] = (n/7);
            if(n%7 >= (i + 1))
                v[i]++;
        }
        int ans = 0;
        for(int i = 1; i <= 7; i++){
            int a = i, b = i + v[i-1] - 1;

            ans += ((v[i-1]) * (a + b))/2;
        }


        return ans;
    }
};