class Solution {
public:

    static bool comp(vector<int> a, vector<int> b){
        if(a[0] != b[0])
            return a[0] < b[0];
        else
            return a[1] < b[1];
    }

    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(begin(intervals), end(intervals), comp);

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i< n; i++){
            if(!pq.empty()){
                if(pq.top() < intervals[i][0])
                    pq.pop();
                pq.push(intervals[i][1]);
            }
            else
                pq.push(intervals[i][1]);
        }

        return pq.size();
    }
};