class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        for(int i : nums){
            min_heap.push(i * i);
        }

        vector<int> res;
        while(!min_heap.empty()){
            res.push_back(min_heap.top());
            min_heap.pop();
        }

        return res;
    }
};