class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> st;
        for(int i  : nums)
        {
            if(i > 0)
                st.insert(i);
        }
        int prev = 0;
        for(auto &x : st){
            if(x - prev > 1){
                return prev + 1;
            }
            else{
                prev = x;
            }
        }


        return prev + 1;
    }
};