class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fl, vector<vector<int>>& sl) {
        int n = fl.size(), m = sl.size();

        int i = 0, j = 0;
        vector<vector<int>> ans;
        while(i < n && j < m){
            if(max(fl[i][0], sl[j][0]) <= min(fl[i][1], sl[j][1])){
                vector<int> cur;
                cur.push_back(max(fl[i][0], sl[j][0]));
                cur.push_back(min(fl[i][1], sl[j][1]));
                // cur.add(Math.max(fl[i][0], sl[j][0]));
                // cur.add(Math.min(fl[i][1], sl[j][1]));
                ans.push_back(cur);
            }

            if(fl[i][1] <= sl[j][1])
                i++;
            else
                j++;
        }

        return ans;
    }
};