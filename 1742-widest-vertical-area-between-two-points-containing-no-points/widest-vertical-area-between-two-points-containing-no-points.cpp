class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();

        priority_queue<int> pq;
        for(int i = 0; i < n; i ++){
            pq.push(points[i][0]);
        }

        int pt = pq.top();
        pq.pop();
        int ans = INT_MIN;
        while(!pq.empty()){
            ans = max(ans, abs(pt - pq.top()));
            pt = pq.top();
            pq.pop();
        }
        return ans;
    }
};