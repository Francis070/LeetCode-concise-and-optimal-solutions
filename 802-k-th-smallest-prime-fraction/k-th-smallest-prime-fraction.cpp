class Solution {
public:

    vector<int> solve(double mid, vector<int> & arr){
        int cnt = 0, num = arr[0], den = arr[arr.size() - 1];
        int i = 0, n = arr.size();
        for( int j = 1; j < n; j++){
            while(arr[i]*1.0 <= double(mid * arr[j])){
                i++;
                
            }
            
            cnt += i;
            if(i > 0 && double(arr[i-1] * den) > double(arr[j] * num)){
                num = arr[i-1];
                den = arr[j];
            }
        }

        return {cnt, num, den};
    }

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();

        double low = ((arr[0] * 1.0) / arr[n-1]), high = 1.0;


        while(low < high){  
            double mid = (low + high)/2;

            vector<int> v = solve(mid, arr);
            if(v[0] == k){
                return {v[1], v[2]};
            }
            else if(v[0] > k){
                high = mid;
            }
            else if(v[0] < k){
                low = mid;
            }
        }

        return {1, 1};
    }
};