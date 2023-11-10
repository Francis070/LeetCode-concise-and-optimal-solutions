class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ap) {
        int n = ap.size();
        vector<int> ans;

        set<int> st;

        unordered_map<int, vector<int>> um;

        for(int i =0; i < n; i++){
            um[ap[i][0]].push_back(ap[i][1]);
            um[ap[i][1]].push_back(ap[i][0]);
        }

        int start = INT_MIN, end = INT_MIN;

        for(auto & x : um){
            if(x.second.size() == 1){
                if(start == INT_MIN)
                    start = x.first;
                else
                    end = x.first;
            }
        }
        int cur = start;
        st.insert(cur);
        ans.push_back(cur);
        // cout<<start<<" "<<end;
        while(cur != end){
            for(int i =0; i < um[cur].size(); i++){
                if(st.find(um[cur][i]) == st.end()){
                    cur = um[cur][i];
                    st.insert(cur);
                    ans.push_back(cur);
                }
            }
        }

        // ans.push_back(end);
        return ans;
    }
};