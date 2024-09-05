class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sumgiven = 0, m = rolls.size();
        vector<int > ans;
        for(int x : rolls)
            sumgiven += x;

        int reqsum = (mean * (n + m)) - sumgiven;
        cout<<reqsum;
        if((n * 6) < (reqsum) || n > reqsum)
            return ans;

        int w = n;
        while((reqsum - 6) > (w - 1)){
            ans.push_back(6);
            reqsum -= 6;
            w--;
        }

        if(w > 0){
            while(w > 1){
                w--;
                reqsum--;
                ans.push_back(1);
            }
            ans.push_back(reqsum);
        }

        return ans;
        
    }
};