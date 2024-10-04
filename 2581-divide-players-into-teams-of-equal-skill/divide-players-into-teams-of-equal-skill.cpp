#define ll long long
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        unordered_map<int, int> um;
        ll sum = 0;
        for(auto x  : skill){
            sum += x;
            um[x]++;
        }

        if((sum * 2)%n != 0){
            return -1;
        }

        ll se = (sum * 2)/n;
        ll ans = 0;
        for(int i= 0; i < n; i++){
            int f = skill[i];
            int s = se - f;
            if(um[f] > 0){
                if(um.find(s) != um.end() && um[s] > 0){
                    um[s]--;
                    um[f]--;
                    if(um.find(s) != um.end() && um[s] == 0){
                        um.erase(s);
                    }
                    if(um.find(f) != um.end() && um[f] == 0){
                        um.erase(f);
                    }
                    
                    ans += (f * s);
                }
                else 
                    return -1;

            }
        }

        // if(um.size() > 0)
        //     return -1;
        
        return ans;
    }
};