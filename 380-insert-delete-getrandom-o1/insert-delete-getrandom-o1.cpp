class RandomizedSet {
public: 
    unordered_map<int, int> us;
    // queue<int> q; 
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(us.find(val) == us.end()){
            v.push_back(val);

            us[val] = v.size() - 1;
            // q.push(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(us.find(val) != us.end()){
            int pos = us[val];
            int val2 = v.back();
            int pos2 = us[val2];
            swap(v[pos], v[pos2]);
            us[val2] = pos;
            v.pop_back();
            us.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        // while(us.find(q.front()) == us.end())
        //     q.pop();
        // int val = q.front();
        // q.pop();
        // q.push(val);
        // return val;
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */