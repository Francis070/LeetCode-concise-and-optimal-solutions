class MyCircularDeque {
public:
    deque<int> dq;
    int maxEle, totEle;
    MyCircularDeque(int k) {
        // dq.resize(k);
        maxEle = k;
        totEle = 0;
    }
    
    bool insertFront(int value) {
        if(totEle == maxEle){
            return false;
        }

        dq.push_front(value);
        totEle++;
        return true;
    }
    
    bool insertLast(int value) {
        if(totEle == maxEle){
            return false;
        }

        dq.push_back(value);
        totEle++;
        return true;
    }
    
    bool deleteFront() {
        if(totEle == 0){
            return false;
        }

        dq.pop_front();
        totEle--;
        return true;
    }
    
    bool deleteLast() {
        if(totEle == 0){
            return false;
        }

        dq.pop_back();
        totEle--;
        return true;
    }
    
    int getFront() {
        if(totEle == 0)
            return -1;
        return dq.front();
    }
    
    int getRear() {
        if(totEle == 0)
            return -1;
        return dq.back();
    }
    
    bool isEmpty() {
        return totEle == 0;
    }
    
    bool isFull() {
        return totEle == maxEle;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */