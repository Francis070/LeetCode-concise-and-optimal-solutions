class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        map<int, int> mp;
        for(int x: arr1){
            mp[x]++;
        }
        vector<int> ans;
        for(int x : arr2){
            int v = x;
            int cnt = mp[v];

            for(int i = 0; i < cnt; i++){
                ans.push_back(v);
            }
            mp.erase(v);
        }

        for(auto & x : mp){
            int v = x.first;
            int cnt = x.second;

            for(int i = 0; i < cnt; i++){
                ans.push_back(v);
            }
        }

        return ans;
    }
};