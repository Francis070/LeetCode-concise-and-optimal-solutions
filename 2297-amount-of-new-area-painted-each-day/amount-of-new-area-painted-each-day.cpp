class Solution {
public:

    int get_painted_area(int r, int s, int e,  map<int, int> &mp){
        // cout<<r<<"---"<<endl;
        // for(auto & x : mp)
        //     cout<<x.first<<" "<<x.second<<endl;
        // cout<<endl;

        if(mp.size() == 0){
            mp[s] = e;
            return e - s;
        }
        else if(mp.lower_bound(s) == mp.end()){
            map<int, int>::iterator it = prev(mp.end());
            if(it->second <= s){
                mp[s] = e;
                return e - s;
            }
            else if(e > it->second){
                int val = it->second;
                it->second = e;
                return e - val;
            }
            else{
                return 0;
            }
        }
        // cout<<"here"<<endl;
        map<int, int>::iterator beg = mp.lower_bound(s),
        end = mp.upper_bound(e);

        if(beg != mp.begin() && prev(beg)->second > s){
            if(prev(beg)->second >= e)
                return 0;
            else
                s = prev(beg)->second;
        }
        
        int to_paint = 0;
        int temp_s = s, temp_e = e;
        // cout<<temp_s<<" "<<temp_e<<endl;
        vector<map<int, int>::iterator> vi;
        for(auto it = beg; it != end; it++){
            
            int x = it->first, y = it->second;
            vi.push_back(it);
            e = max(e, y);
            if(temp_s <= x){
                to_paint += (x - temp_s);
                temp_s = y;
            }
            if(temp_s >= temp_e)
                break;
        }

        if(temp_s < temp_e){
            to_paint += (temp_e - temp_s);
        }

        for(auto x : vi)
            mp.erase(x);

        mp[s] = e;
        return to_paint;
    }

    vector<int> amountPainted(vector<vector<int>>& paint) {
        int n = paint.size();

        vector<int> ans(n, 0);

        map<int, int> mp;
        for(int i = 0; i < n; i++){
            int start = paint[i][0], end = paint[i][1];
            int painted_area = get_painted_area(i, start, end, mp);

            ans[i] = painted_area;
        }

        return ans;
    }
};