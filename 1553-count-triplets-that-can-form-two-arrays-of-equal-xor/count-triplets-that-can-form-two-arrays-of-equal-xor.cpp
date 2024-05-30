class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, vector<int>> ke;
        unordered_map<int, vector<pair<int, int>>> kp;

        for(int i = 0; i < n; i++){
            int cur = 0;
            for(int j = i; j < n; j++){
                cur ^= arr[j];
                ke[cur].push_back(j);
                kp[cur].push_back({i, j});
            }
        }

        for(auto & x : ke){
            sort(x.second.begin(), x.second.end());
        }

        int ans = 0;

        for(auto & x : kp){
            int val = x.first;

            vector<int> cur = ke[val];
            for(auto & y : x.second){
                int st = y.first;
                int enst = st - 1;

                if(enst >= 0){
                    int spos = lower_bound(begin(cur), end(cur), enst) - begin(cur);
                    int epos = upper_bound(begin(cur), end(cur), enst) - begin(cur);

                    ans += (epos - spos);
                }
            }
        }

        return ans;
    }
};