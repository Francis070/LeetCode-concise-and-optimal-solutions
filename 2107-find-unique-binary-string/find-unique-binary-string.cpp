class Solution {
public:

    string change(int er, int req){
        // cout<<er<<endl;
        string res = "";
        while(er > 0){
            if(er & 1){
                res = '1' + res;
            }
            else{
                res = '0' + res;
            }
            er >>= 1;
        }
        // int 
        // cout<<res<<endl;
        if(res.size() < req){
            int rem = req - res.size();
            for(int i = 0; i < rem; i++){
                res = "0" + res;
            }
        }
        // for(int i = 0; i <= (req - res.size()); i++){
        //     res = '0' + res;
        // }
        return res;
    }

    bool find(string st, vector<string>& nums){
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] == st)
                return false;
        }

        return true;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size(), m = nums[0].size();

        int min_v = 0, max_v = pow(2, m) - 1;
        // cout<<min_v<<" "<<max_v<<endl;

        for(int i = min_v; i <= max_v; i++){
            string get_st = change(i, m);
            // cout<<get_st<<endl;
            if(find(get_st, nums))
                return get_st;
        }

        return "";
    }
};