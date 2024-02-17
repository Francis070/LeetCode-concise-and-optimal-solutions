class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();

        vector<int> bricks_req;

        for(int j = 1; j < n; j++)
            if(heights[j] > heights[j-1]) bricks_req.push_back(heights[j] - heights[j-1]);
        
        // for(int x : bricks_req)
        //     cout<<x<<" ";
        // cout<<endl;
        priority_queue<int, vector<int>, greater<int>> mnq;
        int i;
        for(i = 0; i < bricks_req.size(); i++){
            int cur = bricks_req[i];

            int mnt = -1;

            if(mnq.size() < ladders){
                mnq.push(cur);
                // ladders--;
            }
            else{
                if(!mnq.empty())
                    mnt = mnq.top();
                
                if(mnt == -1 || mnt > cur){
                    if(cur <= bricks){
                        bricks -= cur;
                    }
                    else{
                        break;
                    }
                }
                else{
                    mnq.pop();
                    mnq.push(cur);

                    if(mnt <= bricks){
                        bricks -= mnt;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        // cout<<i;
        int ans = 0;
        for(int j = 1; j < n; j++, ans++){
            if(heights[j] > heights[j-1]){
                if(i - 1 >= 0)
                    i--;
                else
                    break;
            }
        }

        return ans;
    }
};