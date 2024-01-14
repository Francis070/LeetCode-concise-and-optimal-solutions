class Solution {
public:
    
    bool chk(unsigned long long mid, unsigned long long k, int x){
        unsigned long long total = 0;
        
        int j = 0;
        unsigned long long t = mid;
        while(t > 0){
            j++;
            t>>= 1;
        }
        // cout<<j<<endl;
        vector<pair<unsigned long long, unsigned long long>> v(j);
        v[0] = {2, 1};
        
        for(int i = 1; i < v.size(); i++){
            v[i].first = v[i-1].first * 2; 
            v[i].second = v[i-1].second * 2; 
        }
//         for(auto e : v){
//             cout<<e.first<<" "<<e.second<<":";
            
//         }
//         cout<<endl;
        unsigned long long we = mid + 1;
        // cout<<we<<endl;
        for(int i = 0; i < v.size(); i++){
            unsigned long long temp = 0;
            if(((i + 1) % x) == 0){
                
                unsigned long long q = (we/v[i].first) * v[i].second;
                // cout<<" "<<q<<" ";
                temp += q;
                
                if((we % v[i].first) != 0){
                    if((we % v[i].first) >= v[i].second){
                        // cout<<"r"<<((we % v[i].first) - v[i].second)<<"r";
                        temp += (we % v[i].first) - v[i].second;
                    }
                    // unsigned long long rem = max(static_cast<unsigned long long>(0), (we % v[i].first) - v[i].second);
                    // cout<<"r"<<rem<<"r";
                    // temp += rem;
                }
        
            }
            // cout<<temp<<":";
            total += temp;
        }
        // cout<<endl;
        // cout<<mid<<" "<<total<<endl;
        return total <= k;
    }
    
    long long findMaximumNumber(long long k, int x) {
        unsigned long long low = 1, 
        // high = 10;
        high = LLONG_MAX - 50;
        
        unsigned long long ans = -1;
        
        while(low <= high){
            unsigned long long mid = (low + high)/2;
            
            if(chk(mid, k, x)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        
        return ans;
    }
};