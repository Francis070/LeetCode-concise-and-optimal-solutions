class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& subs) {
        int n = nums.size(), m = subs.size();
        vector<int> ind(n + 1, 0);
        vector<vector<int>> adj(n + 1);

        for(int i = 0; i < m; i++){
            for(int j = 1; j < subs[i].size(); j++){
                adj[subs[i][j-1]].push_back(subs[i][j]);
                ind[subs[i][j]]++;
            }
        }

        

        queue<int> q;
        for(int i = 1; i <= n; i++){
            if(ind[i] == 0)
                q.push(i);
        }
        // cout<<q.front();
        if(q.size() != 1)  
            return false;
        while(!q.empty()){
            int top = q.front();
            q.pop();

            for(auto x : adj[top]){
                ind[x]--;
                if(ind[x] == 0)
                    q.push(x);
            }
            // cout<<q.size()<<" "<<q.front()<<endl;
            if(q.size() > 1)  
                return false;
            else if(q.size() < 1)
                break;
        }

        return true;
    }
};