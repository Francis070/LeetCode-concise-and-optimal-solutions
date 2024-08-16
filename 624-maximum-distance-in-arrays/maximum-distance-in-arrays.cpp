class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();

        priority_queue<pair<int, int>> maxp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minp;

        for(int i = 0; i < n; i++){
            int x = arrays[i][0];
            int y = arrays[i].back();
            maxp.push({y, i});
            minp.push({x, i});
        }

        int ans = 0;

        if(maxp.top().second == minp.top().second){
            pair<int, int> mit = minp.top(), mxt = maxp.top();
            minp.pop();
            maxp.pop();
            // pair<int, int> mit2 = minp.top(), mxt2 = maxp.top();
            ans = max(ans, abs(maxp.top().first - mit.first ));
            ans = max(ans, abs(mxt.first - minp.top().first));
        }
        else{
            ans = max(ans, abs(maxp.top().first - minp.top().first));
        }

        return ans;
    }
};