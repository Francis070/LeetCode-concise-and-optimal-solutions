class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int sz = target.size();

        vector<string> ans;

        int prev = 0;
        for(int i = 0; i < sz; i++){
            int dif = max(0, target[i] - prev - 1);

            for(int j = 0; j < dif; j++){
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            ans.push_back("Push");
            prev = target[i];
        }

        return ans;
    }
};