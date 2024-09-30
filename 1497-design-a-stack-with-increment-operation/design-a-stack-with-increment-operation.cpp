class CustomStack {
public:
    vector<int> stk;
    int ms;
    CustomStack(int maxSize) {
        ms = maxSize;
    }
    
    void push(int x) {
        if(stk.size() >= ms)
            return;
        
        stk.push_back(x);
    }
    
    int pop() {
        if(stk.size() == 0)
            return -1;

        int end = stk.back();
        stk.pop_back();
        return end;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < min(static_cast<int>(k), static_cast<int>(stk.size()) ); i++)
            stk[i] += val;

    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */