class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0, n = arr.size();
        
        vector<int> v(n, -1);
        int cm = arr[0];
        for(int i = 0; i < n; i++){
            v[i] = max(cm, arr[i]);
            cm = max(cm, arr[i]);
        }

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