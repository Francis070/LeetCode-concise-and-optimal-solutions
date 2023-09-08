class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        int n1 = p.size(), n2 = t.size();

        sort(p.begin(), p.end());
        sort(t.begin(), t.end());

        int i = 0, j = 0;
        int ans = 0;
        while(i < n1 && j < n2){
            if(t[j] >= p[i]){
                ans++; i++;
            }
            j++;
        }

        return ans;
    }
};