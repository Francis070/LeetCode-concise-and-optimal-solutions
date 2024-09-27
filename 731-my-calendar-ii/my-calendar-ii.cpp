class MyCalendarTwo {
public:
    map<int, vector<int>> mp;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        if(mp.size()== 0){
            mp[start].push_back(end);
            return true;
        }

        auto pose = mp.upper_bound(end);
        vector<pair<int, int>> pairs;

        map<int, vector<int>>::iterator it;
        for(it = mp.begin(); it != pose; it++){
            int fr = it->first;
            for(auto x : it->second){
                if(!(start >= x || end <= fr)){
                    pairs.push_back({fr, x});
                }
            }
        }

        map<int, int> mpDouble;

        for(auto x : pairs){
            if(!bookDouble(x.first, x.second, mpDouble)){
                return false;
            }
        }

        mp[start].push_back(end);
        return true;
    }

    bool bookDouble(int start, int end, map<int, int> &mpd) {
        auto x = mpd.lower_bound(start);

        if(x == mpd.begin() && mpd.size() > 0){
            if(end > x->first){
                return false;
            }
            else {
                mpd[start] = end;
                return true;
            }
        }
        else if(x == mpd.end() && mpd.size() > 0){
            x = prev(x);
            if(start < x->second)
                return false;
            else{
                mpd[start] = end;
                return true;
            }
        }
        else{
            if(mpd.size() == 0){
                mpd[start] = end;
                return true;
            }
            else {
                auto y = prev(x);
                if(start < y->second || end > x->first)
                    return false;
                else{
                    mpd[start] = end;
                    return true;
                }
            }
        }
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */