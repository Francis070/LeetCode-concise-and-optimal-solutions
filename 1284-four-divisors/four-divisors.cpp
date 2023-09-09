class Solution {
public:

    int sumDiv(int r){
        int cnt = 0, sum = 0;

        for(int i = 1; i <= sqrt(r); i++){
            if(r%i == 0){
                if(r/i == i){
                    cnt++;
                    sum += i;
                }
                else{
                    cnt += 2;
                    sum += (r/i + i);
                }
            }
        }
        if(cnt == 4)
            return sum;
        return 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i =0; i < n; i++){
            int x = sumDiv(nums[i]);
            ans += x;
        }

        return ans;
    }
};