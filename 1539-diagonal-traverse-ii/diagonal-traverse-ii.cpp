class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {

        
        // vector<queue<pair<int, int>>> vq; 
        int mx = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mx = max(mx, (int(nums[i].size()) + i));
        }
        vector< priority_queue<pair<int, int>> > v(mx);
        // for(int)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < nums[i].size(); j++){
                int ind = i + j;

                v[ind].push({i, j});
            }
        }

        vector<int> ans;
        for(int i =0 ;  i < mx; i++){
            while(!v[i].empty()){
                auto x = v[i].top();
                v[i].pop();
                ans.push_back(nums[x.first][x.second]);
            }
        }


        return ans;
    }
};