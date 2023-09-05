class Solution {
public:

    static bool comp(int a, int b){
        string x = to_string(a), y = to_string(b);

        string c1 = x + y, c2 = y + x;

        return c1 > c2;   //checking which result will give me greater integer.
    }

    string largestNumber(vector<int>& nums) {
        int n = nums.size();

        string res = "";

        //sorting the elements of the array greedily to get the max element from the array
        sort(nums.begin(), nums.end(), comp);

        //concatenating the numbers in the res variable.
        for(int i =0 ; i < n; i++)
            res += to_string(nums[i]);

        // removing leading zeroes from the string.
        int k = 0;
        while(k < res.size()-1 && res[k] == '0')
            k++;
        
        res = res.substr(k, res.size() - k);

        return res;
    }
};