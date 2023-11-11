class Solution {
public:
    long long maxSpending(vector<vector<int>>& val) {
        long long ans = 0;
        long long r = val.size(), c = val[0].size();
        
        priority_queue<pair<long long, pair<long long, long long>>, vector<pair<long long, pair<long long, long long>>>, greater<pair<long long, pair<long long, long long>>>> pq;
        
        for(int i = 0; i < r; i++){
            pq.push({val[i][c - 1], {i, c-1}});
        }
        long long cnt = 1;
    
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            ans += (cnt * x.first);
            if(x.second.second - 1 >= 0){
                pq.push({val[x.second.first][x.second.second - 1], {x.second.first, x.second.second - 1}});
            }
            cnt++;
        }
        
        return ans;
    }
};