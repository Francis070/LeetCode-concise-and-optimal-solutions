class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();

        unordered_map<int, int> um;

        for(int x : arr){
            um[x]++;
        }

        for(int x : target){
            if(um.find(x) != um.end() && um[x] > 0){
                um[x]--;
                if(um[x] == 0){
                    um.erase(x);
                }
            }
            else{
                return false;
            }
            
        }
        return true;
    }
};