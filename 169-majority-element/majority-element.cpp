class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, number = 0;
        for(int i =0; i < n; i++){
            if(cnt == 0){
                cnt++;
                number = nums[i];
            }
            else{
                if(number == nums[i]){
                    cnt++;
                }
                else{
                    cnt--;
                }
            }
        }

        return number;
    }
};