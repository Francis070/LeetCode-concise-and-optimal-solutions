class SeatManager {
public:
    vector<int> v;
    priority_queue<int, vector<int>, greater<int>> pq;
    SeatManager(int n) {
        v.resize(n+1, 0);
        for(int i = 1; i <= n; i++){
            pq.push(i);
        }
    }
    
    int reserve() {
        int x = pq.top();
        v[x] = 1;
        pq.pop();
        return x;
    }
    
    void unreserve(int seatNumber) {
        v[seatNumber] = 0;
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */