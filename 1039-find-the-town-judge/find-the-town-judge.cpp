class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int, int>> trust_and_beTrusted(n + 1, {0, 0});

        for(int i =0; i < trust.size(); i++){
            int truster = trust[i][0];
            int trustee = trust[i][1];
            trust_and_beTrusted[truster].first++;
            trust_and_beTrusted[trustee].second++;
        }

        for(int i =1; i <= n; i++){
            if(trust_and_beTrusted[i] == make_pair(0, n-1)){
                return i;
            }
        }

        return -1;
    }
};