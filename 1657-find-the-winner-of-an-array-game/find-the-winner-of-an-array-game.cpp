class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();

        int mx = *max_element(arr.begin(), arr.end());

        int cur = arr[0];
        queue<int> q;
        for(int i = 1;i < n; i++)
            q.push(arr[i]);

        // unordered_map<int, int> um;
        int cnt = 0;
        while(cur != mx){
            int x = q.front();
            if(x < cur){
                q.push(x);
                cnt++;
            }
            else{
                q.push(cur);
                cur = x;
                cnt = 1;
            }
            q.pop();
            // um[cur]++;
            if(cnt == k){
                return cur;
            } 
        }

        return mx;
    }
};