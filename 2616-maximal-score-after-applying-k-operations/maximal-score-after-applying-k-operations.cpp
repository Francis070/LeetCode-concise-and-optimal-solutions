#define ll long long
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto x : nums)
            pq.push(x);

        ll ans = 0;
        while(k--){
            int tp = pq.top();
            ans += tp;
            pq.pop();
            tp = ceil(static_cast<double>(tp)/3.0);
            pq.push(tp);
        }

        return ans;
    }

};