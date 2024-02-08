class Solution {
public:

    static bool comp(vector<int> & a, vector<int> & b){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }

    int minMeetingRooms(vector<vector<int>>& ivls) {
        int n = ivls.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        sort(ivls.begin(), ivls.end(), comp);

        pq.push({ivls[0][1], ivls[0][0]});
        int ans = 1;

        for(int i = 1; i < n; i++){
            while(!pq.empty() && pq.top().first <= ivls[i][0])
                pq.pop();
            
            pq.push({ivls[i][1], ivls[i][0]});
            ans = max(ans, static_cast<int>(pq.size()));
        }

        return ans;
    }
};