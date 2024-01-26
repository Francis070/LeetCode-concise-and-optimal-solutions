/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:

    static bool comp(pair<int, int> a, pair<int, int> b){
        if(a.first != b.first)
            return a.first < b.first;
        return a.second < b.second;
        // if(a.second != b.second){
        //     return a.second < b.second;
        // }
        // else{
        //     return a.first < b.first;
        // }
    }

    vector<Interval> employeeFreeTime(vector<vector<Interval>> sc) {
        int n = sc.size();
        vector<pair<int, int>> vp, ni;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < sc[i].size(); j++){
                int x = sc[i][j].start, y = sc[i][j].end;
                vp.push_back({x, y});
            }
        }

        sort(vp.begin(), vp.end(), comp);
        // for(auto x:vp){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        ni.push_back(vp[0]);
        for(int i = 1; i<vp.size(); i++){
            if(vp[i].first <= ni.back().second){
                int mn = min(ni.back().first, vp[i].first);
                int mx = max(ni.back().second, vp[i].second);
                ni.back().first = mn;
                ni.back().second = mx;
            }
            else{
                ni.push_back(vp[i]);
            }
        }
        vector<Interval> ans;
        for(int i = 1; i < ni.size(); i++){
            int x = ni[i-1].second;
            int y = ni[i].first;
            Interval cur;
            cur.start = x;
            cur.end = y;
            // Interval cur = new Interval(x, y);
            ans.push_back(cur);
        }


        return ans;
    }   
};