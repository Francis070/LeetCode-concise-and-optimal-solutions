class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int cur = arr[0], n = arr.size();
        int win= 0;
        for(int i =1; i < n; i++){
            if(cur < arr[i]){
                cur = arr[i];
                win = 0;
            }
            if(++win >= k){
                return cur;
            }
        }

        return *max_element(arr.begin(), arr.end());
    }
};