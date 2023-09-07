class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int ans = 0;
        int points = 0;
        sort(tokens.begin(), tokens.end());

        int i = 0, j = n-1;
        while(i <= j){
            if(power >= tokens[i]){
                points++;
                ans = max(ans, points);
                power -= tokens[i];
                i++;
            }
            else{
                if(points == 0)
                    break;
                else{
                    points--;
                    power += tokens[j];
                    j--;
                }
            }
        }

        return ans;
    }
};