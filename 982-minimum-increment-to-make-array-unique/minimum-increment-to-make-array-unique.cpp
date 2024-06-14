class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        vector<int> v(n);
        int mx = 0;
        set<int> st;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(st.find(nums[i]) != st.end()){
                v[i] = mx;
                st.insert(v[i]);
                mx++;
            }
            else{
                v[i] = nums[i];
                st.insert(v[i]);
                mx = v[i] + 1;
            }

            ans += abs(v[i] - nums[i]);
        }

        return ans;
    }
};

//1 1 2 2 3 7
//1 2 3 4 5 7