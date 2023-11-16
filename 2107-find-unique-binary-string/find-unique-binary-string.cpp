class Solution {
public:
    string ans = "";
    void rec(int ind, int n, string cur, unordered_set<string> &st){
        if(ind == n){
            if(st.find(cur) == st.end())
                ans = cur;
            return;
        }

        rec(ind + 1, n, cur + '0', st);
        if(ans != "")
            return ;
        rec(ind + 1, n, cur + '1', st);
        if(ans != "")
            return;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st(nums.begin(), nums.end());

        rec(0, nums.size(), "", st);

        return ans;
    }
};