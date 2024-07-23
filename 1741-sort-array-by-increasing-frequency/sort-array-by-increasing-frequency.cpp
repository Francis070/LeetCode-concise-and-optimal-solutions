class Solution {
public:

    static bool comp(pair<int, int> a, pair<int, int > b){
        if(a.first != b.first){
            return a.first < b.first;
        }

        return a.second > b.second;
    }

    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> vp;
        unordered_map<int, int> um;

        for(int x : nums){
            um[x]++;
        }

        for(auto & x : um){
            vp.push_back({x.second, x.first});
        }

        sort(begin(vp), end(vp), comp);
        vector<int> ans;
        for(auto & f : vp){
            for(int i = 0; i < f.first; i++){
                ans.push_back(f.second);
            }
        }

        return ans;
    }
};