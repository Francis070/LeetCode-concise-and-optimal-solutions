class Solution {
public:

    static bool comp(pair<int, double> a, pair<int, double> b){
        if(a.second != b.second)
            return a.second < b.second;
            
        return a.first < b.first;
    }

    double mincostToHireWorkers(vector<int>& qu, vector<int>& wa, int k) {
        int n = wa.size();

        vector<pair<int, double>> vp;
        for(int i =0 ; i < n; i++){
            double rat = static_cast<double>(wa[i])/static_cast<double>(qu[i]);
            vp.push_back({qu[i], rat});
        }

        sort(begin(vp), end(vp), comp);
        priority_queue<int> pq;
        long long sum =0;
        for(int i = 0; i < k; i++){
            sum += vp[i].first;
            pq.push(vp[i].first);
        }
        double ans = vp[k-1].second * sum;
        int pt = k;
        while(pt < n){
            sum += vp[pt].first;
            pq.push(vp[pt].first);

            int tp = pq.top();
            pq.pop();
            sum -= tp;

            ans = min(ans, vp[pt].second * sum);
            pt++;
        }

        return ans;
    }
};