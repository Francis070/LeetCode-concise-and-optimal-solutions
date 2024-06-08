#define ll long long

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<ll> pre(n, 0);

        
        map<int, vector<pair<int, int>>> mp;
        for(int i = 0; i < n; i++){
            if(i == 0){
                pre[0] = nums[0];
            }   
            else{
                pre[i] = nums[i] + pre[i-1];
            }
            mp[pre[i]%k].push_back({i, pre[i]});
        }

        // for(ll c : pre){
        //     cout<<c<<" ";
        // }
        // cout<<endl;
        // for(auto & x : mp){
        //     cout<<x.first<<"->";
        //     for(auto &y : x.second)
        //         cout<<y.first<<",";
        //     cout<<endl;
        // }


        for(auto & x : mp){

            // for(auto & y : x.second){
            //     // if(y.second >= k){
            //         if(x.first != 0 && x.second.size() > 1){
            //             return true;
            //         }
            //         else if(x.first == 0)
            //             return true;
            //     // }
            // }

            if(x.first != 0 && x.second.size() > 1){
                // for(auto & y : x.second){
                //     if(y.second >= k){
                //         return true;
                //     }
                // }
                auto & frt = x.second[0];
                auto & lst = x.second.back();

                if((lst.first - frt.first) > 1){
                    return true;
                }
            }
            else if(x.first == 0){
                for(auto & y : x.second){
                    if(y.first > 0){
                        return true;
                    }
                }
            }
            
        }

        return false;
    }
};