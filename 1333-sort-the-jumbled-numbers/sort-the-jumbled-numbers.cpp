class Solution {
public:

    string get(int x, vector<int> & m){
        string res = "";

        string cur = to_string(x);

        for(char c : cur){
            int vt = c - '0';

            res += to_string(m[vt]);
        }

        return res;
    }

    static bool comp(pair<string, int> a, pair<string , int > b){
        int v1 = stoi(a.first);
        int v2 = stoi(b.first);

        return v1 < v2;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {

        vector<pair<string, int>> vp;
        
        for(auto x : nums){
            string ms = get(x, mapping);

            vp.push_back({ms, x});
        }

        sort(begin(vp), end(vp), comp);

        vector<int> ans;
        for(auto x : vp){
            ans.push_back(x.second);
        }

        return ans;
    }
};