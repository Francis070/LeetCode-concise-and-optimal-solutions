class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();

        sort(points.begin(), points.end());
        // int ans = 1;
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            // if overlaps, then no ans++
            //else ans++
            if(i == 0){
                ans.push_back(points[i]);
            }
            else{
                if(points[i][0] <= points[i-1][1] && points[i][0] <= ans.back()[1]){
                    ans.back()[0] = max(ans.back()[0], points[i][0]);
                    ans.back()[1] = min(ans.back()[1], points[i][1]);
                }
                else{
                    ans.push_back(points[i]);
                }
            }
            
        }

        return ans.size();
    }
};