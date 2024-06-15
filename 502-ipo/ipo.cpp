class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int, int>> vp(n);
        for(int i = 0; i < n; i++){
            vp[i].first = capital[i];
            vp[i].second = profits[i];
        }

        sort(begin(vp), end(vp));
        // int ans = w;
        // int pos = 0;
        // while(pos < n && )

        // for(auto & x : vp){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }

        priority_queue<pair<int, int>> pq;

        int pos = 0;
        int ans = w;
        while((pos < n) && (k > 0)){
            // int i = pos;
            while((pos < n) && (vp[pos].first <= w)){
                pq.push({vp[pos].second, vp[pos].first});
                pos++;
            }
            // pos = i;
            // cout<<pos<<" "<<pq.size()<<endl;
            if(pq.empty())
                break;
            int cw = w;
            pair<int, int> tp = pq.top();
            pq.pop();
            // int pr = (tp.first) - (tp.second);
            // w += pr;
            w += tp.first;
            ans += tp.first;
            k--;
            // cout<<pos<<" "<<pq.size()<<endl;
            // while(!pq.empty() && k > 0 && w <= cw){
            //     tp = pq.top();
            //     pq.pop();
            //     pr = (tp.first) - (tp.second);
            //     // w += pr;
            //     w += tp.first;
            //     ans += tp.first;
            //     k--;
            // }
        }
        // cout<<k<<" "<<pq.size()<<endl;
        // while(pq.size() > 0){
        //     pair<int, int> tp = pq.top();
        //     pq.pop();
        //     cout<<tp.first<<endl;
        // }

        while(!pq.empty() && k > 0){
            pair<int, int> tp = pq.top();
            pq.pop();
            ans += tp.first;
            k--;
        }

        return ans;
    }
};