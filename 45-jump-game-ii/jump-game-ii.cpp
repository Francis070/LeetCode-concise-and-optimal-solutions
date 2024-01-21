class Solution {
public:
    int jump(vector<int>& nums) {
        int input_size = nums.size();
        int max_reachable_dist = nums[0];
        int steps = 1;
        if(max_reachable_dist  >= input_size - 1 && input_size > 1)
            return 1;
        if(input_size == 1)
            return 0;
        for(int i = 1; i < input_size ; i++){
            int cur_max = 0;
            for(int j = i; j <= max_reachable_dist ; j++){
                cur_max = max(cur_max, j + nums[j]);
        }
            if(cur_max >= input_size - 1)
                return steps + 1;
            else{
                steps++;
                i = max_reachable_dist;
                max_reachable_dist = cur_max;
            }
        }

        return steps;

    }
};