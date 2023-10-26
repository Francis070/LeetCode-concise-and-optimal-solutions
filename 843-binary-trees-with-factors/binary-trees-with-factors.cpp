class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        sort(arr.begin(), arr.end());

        unordered_map<long long, long long> um;
        for(int i = 0; i < n; i++){
            um[arr[i]]++;
        }

        // for(int x : arr)
        //     cout<<x<<" ";

        // for(int i =0; i < n; i++){
        //     for(int j = i; j < n; j++){
        //         long long x = (arr[i] * arr[j])%mod;
        //         if(um.find(x) != um.end()){
        //             if(i == j){
        //                 um[x] += (um[arr[i]] * um[arr[i]])%mod;
        //             }
        //             else
        //                 um[x] += (um[arr[i]] * um[arr[j]] * 2)%mod;
        //         }
        //     }
        // }

        for(int i = 0; i < n ; i++){
            for(int j = i-1; j>= 0 ; j--){
                if(arr[j] < sqrt(arr[i]))
                    break;
                if((arr[i] % arr[j] == 0) && um.find(arr[i]/arr[j]) != um.end()){
                    if(arr[j] == (arr[i]/arr[j])){
                        um[arr[i]] += (um[arr[j]] * um[arr[j]])%mod;
                    }
                    else{
                        um[arr[i]] += (um[arr[j]] * um[arr[i]/arr[j]] * 2)%mod;
                    }
                }
            }
        }

        // for(auto &x : um){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }

        int ans = 0;
        for(auto &x : um){
            ans = (ans + x.second) % mod;
        }

        return ans;
    }
};