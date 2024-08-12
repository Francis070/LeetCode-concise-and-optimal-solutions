class KthLargest {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    int lar;
    KthLargest(int k, vector<int>& nums) {
        this->lar = k;
        int n = nums.size();
        sort(begin(nums), end(nums), greater<int>());

        for(int i =0 ; i < min(n, k); i++){
            this->right.push(nums[i]);
        }

        for(int i = k; i < n; i++){
            this->left.push(nums[i]);
        }
    }
    
    int add(int val) {
        if(right.size() >= lar && val > right.top()){
            int cur = right.top();
            right.pop();
            left.push(cur);
            right.push(val);
        }
        else{
            if(right.size() < lar){
                right.push(val);
            }
            else{
                left.push(val);
            }
            
        }

        return right.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */