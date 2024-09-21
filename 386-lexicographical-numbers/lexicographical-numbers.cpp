class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string > s;
        for(int i = 1; i <= n; i++){
            string er = to_string(i);
            s.push_back(er);
        }
        sort(begin(s), end(s));

        vector<int> ans;
        for(string d : s){
            ans.push_back(stoi(d));
        }

        return ans;
    }
};