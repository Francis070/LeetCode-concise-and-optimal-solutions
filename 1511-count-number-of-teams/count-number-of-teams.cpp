class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();

        int ans = 0;

        for(int i = 1; i < n - 1; i++){
            int cll = 0, clh = 0, crl = 0, crh = 0;

            for(int j = i - 1; j >= 0; j--){
                if(rating[j] < rating[i]) cll++;
                if(rating[j] > rating[i]) clh++;
            }

            for(int j = i + 1; j < n; j++){
                if(rating[j] < rating[i]) crl++;
                if(rating[j] > rating[i]) crh++;
            }

            ans += (cll * crh) + (clh * crl);
        }

        return ans;
    }
};