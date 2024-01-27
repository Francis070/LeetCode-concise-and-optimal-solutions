class SnapshotArray {
public:
    vector<int> v;
    map<int, map<int, int>> mp;
    int call = -1;
    SnapshotArray(int length) {
        v.resize(length, 0);
        for(int i = 0; i < length; i++)
            mp[i][-1] = 0;
    }
    
    void set(int index, int val) {
        mp[index][call + 1] = val;
    }
    
    int snap() {
        call++;
        // um[call] = v;
        return call;
    }
    
    int get(int index, int snap_id) {
        // map<int, int> temp = mp[index];
        auto pos = mp[index].lower_bound(snap_id);
        if(pos == mp[index].end()){
            return prev(pos)->second;
        }
        else if(pos->first == snap_id){
            return pos->second;
        }
        else{
            return prev(pos)->second;
        }
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */