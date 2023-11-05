class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();

        int mx = *max_element(arr.begin(), arr.end());
        
        int cur = arr[0];
        queue<int> q;
        for(int i = 1;i < n; i++)
            q.push(arr[i]);

        unordered_map<int, int> um;
        while(cur != mx){
            int x = q.front();
            if(x < cur){
                um[cur]++;
                q.pop();
                q.push(x);
                if(um[cur] == k){
                    return cur;
                } 
            }
            else{
                q.push(cur);
                cur = x;
                q.pop();
                um[cur]++;
                if(um[cur] == k){
                    return cur;
                } 
            }
        }

        return mx;
    }
};