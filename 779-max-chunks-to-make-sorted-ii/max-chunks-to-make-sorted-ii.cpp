class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        vector<int> v = arr;
        sort(v.begin(), v.end());

        long long nonsortedsum = 0, sortedsum = 0;
        for(int i = 0; i < n; i++){
            nonsortedsum += v[i];
            sortedsum += arr[i];

            if(sortedsum == nonsortedsum)
                ans++;
        }
        return ans;
    }
};