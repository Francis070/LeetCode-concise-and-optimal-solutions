class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();

        map<int, int> mp;
        for(int i =0 ;  i < n; i++){
            mp[people[i]]++;
        }

        int ans = 0;
        while(mp.size() > 0){
            int val = mp.begin()->first;
            int dval = limit - val;

            auto pos = mp.lower_bound(dval);

            if(pos == mp.end() || (pos->first > dval && pos != mp.begin())){
                pos = prev(pos);
                dval = pos->first;
            }

            if(pos == mp.begin()){
                if(dval < val){
                    mp[val]--;
                }
                else{
                    if(mp[val] > 1){
                        mp[val] -= 2;
                    }
                    else{
                        mp[val]--;
                    }
                }
                

                if(mp[val] == 0)
                    mp.erase(val);
            }
            else{
                mp[val]--;
                mp[dval]--;

                if(mp[val] == 0)
                    mp.erase(val);
                if(mp[dval] == 0)
                    mp.erase(dval);
            }



            ans ++;
        }

        return ans;
    }
};