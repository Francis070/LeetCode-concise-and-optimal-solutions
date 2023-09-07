class Solution {
public:

    static bool comp(pair<int, int> a, pair<int, int> b){
        return a.first > b.first;
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();
        vector<pair<int, int>> v(n);

        for(int i = 0; i < n; i++){
            v[i].first = nums2[i];
            v[i].second = nums1[i];
        }
        sort(v.begin(), v.end(), comp);
        priority_queue<int , vector<int>, greater<int>> pq;

        long long ans = INT_MIN, cs = 0;

        int j = 0, cnt = 0; 
        while(j < n){
            if(cnt + 1 > k){
                cs -= pq.top();
                pq.pop();
                cnt--;
            }

            cs += v[j].second;
            pq.push(v[j].second);
            cnt++;
            if(cnt == k){
                ans = max(ans, v[j].first * cs);
            }
            // else
            //     cnt++;
            j++;
        }

        return ans;
    }
};