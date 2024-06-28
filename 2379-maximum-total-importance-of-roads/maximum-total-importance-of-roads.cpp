#define ll long long int
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ll m = roads.size();

        unordered_map<ll, ll> um;
        for(int i =0;  i< m; i++){
            um[roads[i][0]]++;
            um[roads[i][1]]++;
        }

        priority_queue<pair<ll, ll>> pq;
        for(auto & x : um){
            pq.push({x.second, x.first});
        }
        ll ans = 0;
        ll cnt = n;
        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();
            ans += (cnt * p.first);
            cnt--;
        }

        return ans;
    }
};