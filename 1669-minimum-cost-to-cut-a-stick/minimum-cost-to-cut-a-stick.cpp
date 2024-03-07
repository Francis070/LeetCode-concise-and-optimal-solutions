class Solution {
public:

    int get_min_cost(int start, int end, vector<int> &cuts, map<pair<int, int>, int> &dp){

        if(end - start <= 1)
            return 0;

        if(dp.find({start, end}) != dp.end() )
            return dp[{start, end}];


        int curmin = 1e8;

        for(int i = start + 1; i < end; i++){
            int minn = get_min_cost(start, i, cuts, dp) + get_min_cost(i, end, cuts, dp);
            
            curmin = min(curmin, (cuts[end] - cuts[start]) + minn);
        }
        
        return dp[{start, end}] = curmin;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(begin(cuts), end(cuts));

        int start = 0, end = cuts.size() - 1;
        map<pair<int, int>, int> dp;
        int ans = get_min_cost(start, end, cuts, dp);

        return ans;
    }
};