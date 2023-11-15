class MyCalendar {
public:
    map<int, int> cal;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto pos = cal.lower_bound(start);
        if(cal.size() == 0){
            cal[start] = end;
            return true;
        }
        else if(pos == cal.begin()){
            if(pos->first < end){
                return false;
            }
            else{
                cal[start] = end;
                return true;
            }
        }
        else if(pos == cal.end()){
            if(prev(pos)->second > start)
                return false;
            else{
                cal[start] = end;
                return true;
            }
        }
        else{
            if(start == pos->first)
                return false;
            else if(pos->first < end || prev(pos)->second > start)
                return false;
            else{
                cal[start] = end;
                return true;
            }
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */