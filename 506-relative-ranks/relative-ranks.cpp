class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        map<int, string> mp;
        for(int i : score){
            mp[i] = "";
        }

        int cnt = score.size();
        for(auto & x : mp){
            if(cnt  > 3){
                x.second = to_string(cnt);
            }
            else{
                if(cnt == 3){
                    x.second = "Bronze Medal";
                }
                else if(cnt == 2){
                    x.second = "Silver Medal";
                }
                else if(cnt == 1){
                    x.second = "Gold Medal";
                }
            }
            cnt--;
        }

        vector<string > vs;
        for(int i : score){
            vs.push_back(mp[i]);
        }

        return vs;
    }
};