class Solution {
public:

    static bool comp(int a, int b){
        string x = to_string(a), y = to_string(b);

        string c1 = x + y, c2 = y + x;

        return c1 > c2;

    }

    string largestNumber(vector<int>& nums) {
        int n = nums.size();

        string res = "";

        sort(nums.begin(), nums.end(), comp);

        for(int i =0 ; i < n; i++)
            res += to_string(nums[i]);
        int k = 0;

        while(k < res.size()-1 && res[k] == '0')
            k++;
        
        res = res.substr(k, res.size() - k);

        return res;
    }
};