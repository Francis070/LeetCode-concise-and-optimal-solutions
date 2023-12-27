class Solution {
public:
    int minCost(string colors, vector<int>& nt) {
        int n = colors.size();

        int ans = 0;

        for(int i = 1; i < n; i++){
            if(colors[i] == colors[i-1]){
                int j = i;

                ans += nt[i-1];
                int mx = nt[i-1];
                while(colors[j] == colors[j-1] && j < n){

                    mx = max(mx, nt[j]);
                    ans += nt[j];
                    j++;
                }

                ans -= mx;

                i = j;
            }
        }

        return ans;
    }
};