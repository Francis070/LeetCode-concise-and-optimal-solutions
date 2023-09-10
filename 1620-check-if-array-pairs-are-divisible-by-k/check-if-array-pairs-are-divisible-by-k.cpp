class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();

        unordered_map<int, int> um;
        for(int i = 0; i < n; i ++){
            um[(arr[i] % k + k)%k]++;
        }

        for(auto x : um){
            if(x.second > 0){
                int a = x.first;
                int b = (k - x.first)%k;

                if(um.find(b) == um.end() || (a == b && (um[a] % 2 == 1)) || (a != b && um[a] != um[b]))
                    return false;

                um[a] = 0; um[b] = 0;
            }
        }

        return true;
    }
};