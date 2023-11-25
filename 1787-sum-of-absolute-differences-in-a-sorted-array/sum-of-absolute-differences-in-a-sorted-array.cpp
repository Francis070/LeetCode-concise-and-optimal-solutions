class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int nums_size = nums.size();

        vector<int> prefix_sum(nums_size, 0), result(nums_size, 0);

        for(int pos = 0; pos < nums_size; pos++){
            if(pos == 0)
                prefix_sum[0] = nums[0];
            else{
                prefix_sum[pos] = prefix_sum[pos - 1] + nums[pos];
            }
        }   

        for(int pos = 0; pos < nums_size; pos++){
            
            int current_value = 0;

            //left side
            if(pos != 0){
                int elements = pos;
                int sum = prefix_sum[pos - 1];

                current_value += (elements * nums[pos]) - sum;
            }

            //right side
            if(pos != (nums_size - 1)){
                int elements = nums_size - pos - 1;
                int sum = prefix_sum[nums_size - 1] - prefix_sum[pos];

                current_value += (sum - (elements * nums[pos]));
            }

            result[pos] = current_value;
        }

        return result;
    }
};

//requirement gathering

// nums = integer array
// nums.length() = 1e5
// n = nums.length()

// either - O(n) or O(nlogn)

// range of nums[i] => 1 <= nums[i] <= 1e4

// {    2   3   5   7    }
//      0   1   2   3

// abs() -> absolute value function

// result[0] = abs(2 - 3) + abs(2 - 5) + abs(2 - 7)
// result[1] = abs(3 - 2) + abs(3 - 5) + abs(3 - 7)
// result[2] = abs(5 - 2) + abs(5 - 3) + abs(5 - 7)
// result[3] = abs(7 - 2) + abs(7 - 3) + abs(7 - 5)

// result = { 9  7  7  11 }

// //approaches

// brute force = O(n^2)

// // optimised approach

// {    2   3   5   7    }
//      2   5   10  17

// for index 0 = (3 + 5 + 7) - (3 * 2)
//     result[0] = 9

// for index 1 = ((1 * 3) - 2) + (12 - (2 * 3))
//     result[1] = 7