class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int mx = INT_MIN;
        int dif = INT_MAX;
        for(int i = 0; i < n; i++){
            pq.push({nums[i][0], {i, 0}});
            mx = max(mx, nums[i][0]);
        }
        vector<int> ans(2, -1);
        while(true){
            //check
            pair<int, pair<int, int>> tp = pq.top();
            int mn = tp.first;
            pq.pop();

            if(mx - mn < dif){
                dif = mx - mn;
                ans[0] = mn;
                ans[1] = mx;
            }

            if(nums[tp.second.first].size() == tp.second.second + 1)
                break;
            

            int ni = tp.second.second + 1;
            int nii = tp.second.first;


            mx = max(mx, nums[nii][ni]);

            pq.push({nums[nii][ni] , {nii, ni}});
        }

        return ans;
    }
};