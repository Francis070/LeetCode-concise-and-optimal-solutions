class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> v(n + 1, 0);
        int flip = 0;
        int rs = 0;
        for(int i = 0; i <= n - k; i++){
            rs += v[i];
            if(nums[i] == 0){
                if(rs % 2 == 0){
                    flip++;
                    v[i] += 1;
                    v[i + k] -= 1;
                    rs += 1;
                }
            }
            else{
                if(rs % 2 == 1){
                    flip ++;
                    v[i] += 1;
                    v[i + k] -= 1;
                    rs += 1;
                }
            }
        }

        int rt = 0;
        vector<int> ano(n + 1);
        for(int i =0; i < n; i++){
            rt += v[i];
            ano[i] = rt;
            // cout<<ano[i]<<" ";
        }

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                if(ano[i] % 2 == 1)
                    nums[i] = 1;
            }
            else{
                if(ano[i] % 2 == 1)
                    nums[i] = 0;
            }

            if(nums[i] == 0)
                return -1;
        }

        return flip;

        // cout<<endl;
        // return 0;
    }
};