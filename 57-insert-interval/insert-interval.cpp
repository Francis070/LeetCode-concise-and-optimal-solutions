class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> ans;
        
        intervals.push_back(newInterval);
        int n = intervals.size();

        sort(begin(intervals), end(intervals));

        for(int i = 0; i < n; i++){
            if(i == 0){
                ans.push_back(intervals[0]);
            }
            else{
                // check if merges
                if(intervals[i][0] <= ans.back()[1]){
                    ans.back()[1] = max(ans.back()[1], intervals[i][1]);
                }
                else{
                    ans.push_back(intervals[i]);
                }
            }
        }

        return ans;
    }
};