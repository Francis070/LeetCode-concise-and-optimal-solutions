class Solution {
public:

    static bool comp(string a, string b){
        int af = stoi(a.substr(0, 2)), as = stoi(a.substr(3, 2));
        int bf = stoi(b.substr(0, 2)), bs = stoi(b.substr(3, 2));

        if(af != bf){
            return af < bf;
        }
        else{
            return as < bs;
        }
    }

    int minSub(string a, string b){
        int af = stoi(a.substr(0, 2)), as = stoi(a.substr(3, 2));
        int bf = stoi(b.substr(0, 2)), bs = stoi(b.substr(3, 2));

        int at = (af * 60 )+ as, bt = (bf * 60) + bs;

        return abs(at - bt);
    }

    int findMinDifference(vector<string>& tp) {
        int n = tp.size();

        sort(begin(tp), end(tp), comp);
        
        int ans = 1e8;
        for(int i = 1; i < n; i++){
            int sub = minSub(tp[i], tp[i - 1]);
            ans = min(sub, ans);
        }

        int af = stoi(tp[0].substr(0, 2)), as = stoi(tp[0].substr(3, 2));
        int bf = stoi(tp.back().substr(0, 2)), bs = stoi(tp.back().substr(3, 2));
        int at = ((af + 24) * 60 )+ as, bt = (bf * 60) + bs;

        ans = min(ans, abs(at - bt));

        return ans;
    }
};