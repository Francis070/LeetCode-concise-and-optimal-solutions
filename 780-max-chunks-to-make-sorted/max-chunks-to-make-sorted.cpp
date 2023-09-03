class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0, n = arr.size();
        
        // we are precalculating the array with max prefix.
        vector<int> v(n, -1);
        int curmax = arr[0];
        for(int i = 0; i < n; i++){
            v[i] = max(curmax, arr[i]);
            curmax = max(curmax, arr[i]);
        }


        // now we are checking if the index is equal to the value present in that index, if not then they belong to the same chunk.
        int j = 0;

        while(j < n){
            while(j != v[j]){
                j = v[j];
            }
            ans++;
            j++;
        }

        return ans;
    }
};