#define ll long long

class Solution {
public:
    int bagOfTokensScore(vector<int>& token, int pow) {
        int n = token.size();
        sort(begin(token), end(token));

        int i = 0, j = n-1;
        int sc = 0;
        int msc = 0;

        while(i <= j){
            if(sc == 0){
                if(pow >= token[i]){
                    pow -= token[i];
                    sc++;
                    msc = max(msc, sc);
                    i++;
                }
                else{
                    break;
                }
            }
            else{
                if(pow >= token[i]){
                    pow -= token[i];
                    sc++;
                    msc = max(msc, sc);
                    i++;
                }
                else{
                    sc--;
                    pow += token[j];
                    j--;
                }
            }
        }

        return msc;

    }
};