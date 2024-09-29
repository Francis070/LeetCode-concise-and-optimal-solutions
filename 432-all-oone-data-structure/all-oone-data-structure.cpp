class AllOne {
public:
    map<string, int> freq;
    map<int, set<string>> list;
    AllOne() {
        
    }
    
    void inc(string key) {
        if(freq.count(key)){
            int fq = freq[key];
            int ft = fq+1;

            if(list[fq].size() == 1){
                list.erase(fq);
            }
            else{
                list[fq].erase(key);
            }

            list[ft].insert(key);
            freq[key] = ft;
        }
        else{
            freq[key] = 1;
            list[1].insert(key);
        }
    }
    
    void dec(string key) {
        if(freq[key]== 1){
            if(list[1].size() == 1){
                list.erase(1);
            }
            else{
                list[1].erase(key);
            }

            freq.erase(key);
        }
        else{
            int fq = freq[key];
            int ft = fq - 1;

            list[fq].erase(key);
            list[ft].insert(key);
            if(list[fq].size() == 0)
                list.erase(fq);
            freq[key] = ft;
        }
    }
    
    string getMaxKey() {
        if(freq.size() == 0)
            return "";
        else{
            return *(prev(list.end())->second.begin());
        }
    }
    
    string getMinKey() {
        if(freq.size() == 0)
            return "";
        else{
            return *(list.begin()->second.begin());
        }
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */