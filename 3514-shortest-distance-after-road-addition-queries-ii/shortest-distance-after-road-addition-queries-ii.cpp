class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        
        map<int, int> mp;
        vector<int> ans;
        int rt = n - 1;
        for(int i = 0; i < m; i++){
            int x = queries[i][0], y = queries[i][1];
            
            auto st = mp.lower_bound(x), en = mp.lower_bound(y);
            int cur = rt;
            bool chk = false;

            if(st == mp.end() || en == mp.begin()|| (st != mp.begin() && x >= prev(st)->second && y <= st->first)){
                if(st == mp.end() && st != mp.begin() && prev(st)->second >= y){
                    cur = rt;
                }
                else{
                    cur = cur + 1 - (y - x);
                    chk = true;
                }
            }
            else{
                if((x == st->first && y < st->second) || (st != mp.begin() && y <= prev(st)->second)){
                    cur = rt;
                }
                else{
                    if(st == prev(en)){
                        cur = cur + 1 - (y - x);
                        if(st != mp.end()){
                            cur = cur - 1 + (st->second - st->first);
                            mp.erase(st);
                        }

                    }
                    else{
                        for(auto it = st; it != en; it++){
                            cur = cur - 1 + (it->second - it->first);
                        }

                        for(auto it = st; it != en; it++){
                            mp.erase(it);
                        }
                        cur = cur + 1 - (y - x);
                    }
                    chk = true;
                }
            }
            
            if(chk){
                mp[x] = y;
            }
            
            
            rt = cur;
            ans.push_back(rt);
            
        }
        
        return ans;
    }
};