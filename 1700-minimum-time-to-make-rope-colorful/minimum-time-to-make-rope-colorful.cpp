class Solution {
public:
    int minCost(string colors, vector<int>& nt) {
        int n = colors.size();

        int ans = 0;
        // priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<int> pq;

        for(int i = 1; i < n; i++){
            if(colors[i] == colors[i-1]){
                int j = i;
                pq.push(nt[i-1]);
                while(colors[j] == colors[j-1] && j < n){
                    pq.push(nt[j]);
                    j++;
                }
                pq.pop();

                while(!pq.empty()){
                    ans += pq.top();
                    pq.pop();
                }
                i = j;
            }
        }

        return ans;
    }
};