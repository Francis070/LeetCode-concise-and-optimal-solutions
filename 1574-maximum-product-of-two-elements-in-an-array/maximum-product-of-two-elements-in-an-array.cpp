class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < n; i++){
            pq.push(nums[i]);
            if(pq.size() > 2)
                pq.pop();
        }

        int a = pq.top();
        pq.pop();
        int b = pq.top();

        return ((a - 1) * (b -1));
    }
};