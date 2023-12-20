class Solution {
public:
    int buyChoco(vector<int>& pr, int mo) {
        int n = pr.size();
        sort(pr.begin(), pr.end());
        if(pr[0] + pr[1] <= mo){
            return (mo - (pr[0] + pr[1]));
        }
        return mo;
        // for(int i = 0; i < n; i++){
        //     cout<<pr[i]<<" ";
        // }
        // int i = 0; int j = n-1;
        // bool ch = false;
        // int ans = INT_MAX;

        // while(i < j){
        //     if((pr[i] + pr[j]) <= mo){
        //         ch = true;
        //         ans = min(ans, pr[i] + pr[j]);
        //         i++;
        //     }
        //     else{
        //         j--;
        //     }
        // }

        // if(ch){
        //     return mo - ans;
        // }
        // return mo;

    }
};