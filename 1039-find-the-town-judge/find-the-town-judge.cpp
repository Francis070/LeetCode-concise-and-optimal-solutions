class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> whoTrusts(n + 1, 0);
        vector<int> whoIsTrusted(n + 1, 0);

        for(int i = 0; i < trust.size(); i++){
            whoTrusts[trust[i][0]]++;
            whoIsTrusted[trust[i][1]]++;
        }

        int ans = -1;
        for(int i = 1; i <= n; i++)
            if(whoTrusts[i] == 0 && whoIsTrusted[i] == n-1)
                ans = i;
        
        return ans;
    }
};