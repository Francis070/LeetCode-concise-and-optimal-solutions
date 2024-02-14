class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int cnt = n/2;
        int pc = 0, nc = 0;

        int pos_p = -1, neg_p = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0){
                pos_p = i;
                break;
            }
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] < 0){
                neg_p = i;
                break;
            }
        }
        vector<int> ans;
        while(pc < cnt && nc < cnt){
            ans.push_back(nums[pos_p]);
            ans.push_back(nums[neg_p]);
            pc++; 
            nc++;
            for(int i = pos_p + 1; i < n; i++) {
                if(nums[i] > 0){
                    pos_p = i;
                    break;
                }
            }

            for(int i = neg_p + 1; i < n; i++) {
                if(nums[i] < 0){
                    neg_p = i;
                    break;
                }
            }
        }

        return ans;
    }
};