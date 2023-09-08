class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, int> um;

        int ans = -1, mx = INT_MIN;
        for(int i =0; i < n; i++){
            um[edges[i][0]]++;
            um[edges[i][1]]++;
        }

        for(auto x : um){
            if(x.second > mx){
                mx = x.second;
                ans = x.first;
            }
        }

        return ans;
    }
};