class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();

        unordered_map<int, int> win, loose;
        for(int i = 0; i < n; i++){
            win[matches[i][0]]++;
            loose[matches[i][1]]++;
        }

        vector<int> winners, losers;
        for(auto x : win){
            if(loose.find(x.first) == loose.end())
                winners.push_back(x.first);
        }

        for(auto x : loose){
            if(x.second == 1)
                losers.push_back(x.first);
        }
        sort(begin(winners), end(winners));
        sort(begin(losers), end(losers));

        return {winners, losers};
    }
};