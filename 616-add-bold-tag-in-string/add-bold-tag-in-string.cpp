class Solution {
public:

    vector<pair<int, int>> merge(vector<pair<int, int>> vp){
        sort(vp.begin(), vp.end());
        int n = vp.size();

        vector<pair<int, int>> res;
        res.push_back(vp[0]);
        for(int i =1; i < n; i++){
            if(vp[i].first <= res.back().second + 1){
                res.back().first = min(res.back().first, vp[i].first);
                res.back().second = max(res.back().second, vp[i].second);
            }
            else{
                res.push_back(vp[i]);
            }
        }

        return res;
    }
    
    string addBoldTag(string s, vector<string>& words) {
        int n = s.size();
        int m = words.size();

        if(m == 0)
            return s;

        unordered_map<string, vector<int>> um;
        map<int, int> mp;

        for(int i = 0; i < m; i++){
            string temp = words[i];
            for(int j = 0; j < n; j++){
                if(temp[0] == s[j]){
                    um[temp].push_back(j);
                }
            }
        }

        vector<pair<int, int>> vp;
        for(auto & x : um){
            string temp = x.first;
            int l = temp.size();

            vector<int> v = x.second;
            for(int i =0; i < v.size(); i++){
                if(v[i] + l <= n && temp == s.substr(v[i], l)){
                    // cout<<v[i]<<" " << (v[i] + l - 1)<<endl;
                    // merge({v[i], v[i] + l - 1}, mp);
                    vp.push_back({v[i], v[i] + l - 1});
                }
            }
        }

        if(vp.size() == 0)
            return s;
        
        vector<pair<int, int>> new_pair = merge(vp);

        // for(auto x : new_pair)
        //     cout<<x.first<<" "<<x.second<<endl;

        vector<int> bcs;
        
        for(auto &x : new_pair){
            bcs.push_back(x.first);
            bcs.push_back(x.second);
        }

        if(bcs.size() == 0)
            return s;

        string res = "";
        int e = 0;
        for(int i = 0; i < n; i++){
            if(e < bcs.size() && bcs[e] == i){
                if(e % 2 == 0){
                    res = res + "<b>" + s[i];
                }
                else{
                    res = res + s[i] + "</b>";
                }

                e++;
                if(e < bcs.size() && bcs[e] == i){
                    res += "</b>";
                    e++;
                }
            }
            else{
                res += s[i];
            }
        }

        return res;
    }
};