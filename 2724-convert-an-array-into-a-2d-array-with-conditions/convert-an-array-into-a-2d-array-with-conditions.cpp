class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        unordered_map<int,int > um;
        vector<vector<int>> ans;
        for(int i = 0; i < n; i ++)
            um[nums[i]]++;
        
        for(auto &x : um){
            int st = 0, val = x.first, cnt = x.second;
            while(cnt > 0){
                if(ans.size() < st + 1){
                    ans.push_back({val});
                }
                else{
                    ans[st].push_back(val);
                }
                st += 1;
                cnt--;
            }
        }
        //     pq.push({x.second, x.first});
        
        // while(!pq.empty()){
        //     // pair<int, int> cur = pq.top();
        //     int st = 0, val = pq.top().second, cnt = pq.top().first;
        //     pq.pop();
        //     while(cnt > 0){
        //         if(ans.size() < st + 1){
        //             ans.push_back({val});
        //         }
        //         else{
        //             ans[st + 1].push_back(val);
        //         }
        //         st += 1;
        //         cnt--;
        //     }
        // }

        return ans;
    }
};