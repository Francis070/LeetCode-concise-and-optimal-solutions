class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> um;
        for(char c : tasks){
            um[c]++;
        }
        priority_queue<int> pq;
        for(auto & x : um)
            pq.push(x.second);
        int ans = 0;
        while(!pq.empty()){
            int time = 0;
            vector<int> cur;

            for(int i =0; i <= n; i++){
                if(!pq.empty()){
                    int t = pq.top() - 1;
                    time++;
                    pq.pop();
                    cur.push_back(t);
                }
            }

            for(int x : cur)
                if(x > 0)
                    pq.push(x);

            if(pq.empty())
                ans += time;
            else{
                ans += (n + 1);
            }
        }

        return ans;
    }
};