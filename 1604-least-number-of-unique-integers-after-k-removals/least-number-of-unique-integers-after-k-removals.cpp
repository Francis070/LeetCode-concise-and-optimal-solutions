class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> um;
        for(int i  : arr)
            um[i]++;
        vector<int> vt;
        for(auto & x : um){
            vt.push_back(x.second);
        }

        sort(begin(vt), end(vt));
        int pos  = 0;
        for(int i = 0; i < vt.size(); i++, pos++){
            if(vt[pos] <= k){
                k-= vt[pos];
            }
            else{
                break;
            }
        }
        int ans = vt.size() - pos;
        return ans;
    }
};