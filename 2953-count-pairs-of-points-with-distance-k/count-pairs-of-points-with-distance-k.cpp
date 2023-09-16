class Solution {
public:
    int countPairs(vector<vector<int>>& co, int k) {
        int n = co.size();
        
        vector<pair<int, int>> vp;
        for(int i = 0; i < n; i++){
            vp.push_back({co[i][0], co[i][1]});
        }
        
        map<pair<int, int>, int> um;
        for(int i  = 0; i < vp.size(); i++){
            um[{vp[i].first, vp[i].second}]++;
        }
  
        long long ans = 0;

        if(k == 0){
            for(auto & x : um)
            {
                long long cv = x.second;
                ans += (cv * (cv - 1))/2;
            }
        }
        else{
            for(int i = 0; i <= k ; i++){
                for(int j = 0; j < vp.size(); j++){
                    
                    int f = vp[j].first ^ i;
                    int g = vp[j].second ^ (k - i);
                    
                    if(f == vp[j].first && g == vp[j].second)
                        ans +=  um[{f, g}]-1;
                    else
                        ans += um[{f, g}];
                }
            }
            ans /= 2;
        }
            
        return ans;
    }
};