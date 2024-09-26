class MyCalendar {
public:
    map<int, int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto x = mp.lower_bound(start);

        if(x == mp.begin() && mp.size() > 0){
            if(end > x->first){
                return false;
            }
            else {
                mp[start] = end;
                return true;
            }
        }
        else if(x == mp.end() && mp.size() > 0){
            x = prev(x);
            if(start < x->second)
                return false;
            else{
                mp[start] = end;
                return true;
            }
        }
        else{
            if(mp.size() == 0){
                mp[start] = end;
                return true;
            }
            else {
                auto y = prev(x);
                if(start < y->second || end > x->first)
                    return false;
                else{
                    mp[start] = end;
                    return true;
                }
            }
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */