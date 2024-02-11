class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // vector<vector<pair<int, int>>> adj(n);
        // int m = flights.size();

        // for(int i = 0; i< m; i++){
        //     adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        // }

        // int ans = INT_MAX;
        // queue<pair<int, int>> q;
        // q.push({src, 0});

        // while(!q.empty() && k-- >= 0){
        //     int sz = q.size();

        //     while(sz-- > 0){
        //         auto x = q.front();
        //         q.pop();
        //         int node = x.first, len = x.second;

        //         for(auto p : adj[node]){
        //             if(ans <  p.second + len)
        //                 continue;
        //             q.push({p.first, p.second + len});
        //             if(p.first == dst){
        //                 ans = min(ans, p.second + len);
        //             }
        //         }
        //     }

        // }

        // if(ans == INT_MAX)
        //     return -1;
        // return ans;

        vector<int> dist( n, INT_MAX );
        dist[src] = 0;
        
        // Run only K+1 times since we want shortest distance in K hops
        for( int i=0; i <= k; i++ ) {
            vector<int> tmp( dist );
            for( auto flight : flights ) {
                if( dist[ flight[0] ] != INT_MAX ) {
                    tmp[ flight[1] ] = min( tmp[flight[1]], dist[ flight[0] ] + flight[2] );
                }
            }
            dist = tmp;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];

    }
};