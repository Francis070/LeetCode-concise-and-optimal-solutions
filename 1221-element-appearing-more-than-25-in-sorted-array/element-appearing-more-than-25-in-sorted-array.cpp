class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();

        int cnt = 1;
        int noe = n/4;

        for(int i = 1; i  < n; i++){
            if(arr[i] == arr[i- 1]){
                cnt++;
            }
            else{
                cnt = 1;
            }

            if(cnt > noe){
                return arr[i];
            }
        }

        if(noe == 0)
            return arr[0];

        return 0;
    }
};