class Solution {
public:

    void rec(int ind, int sum, vector<int> & nums, vector<int> &get){
        if(ind >= nums.size()){
            get.push_back(sum);
            return;
        }

        //not take
        rec(ind + 1, sum,nums, get);

        //take
        rec(ind + 1, sum + nums[ind],nums, get);

    }

    int minAbsDifference(vector<int>& nums, int goal) { 
        int ans = INT_MAX;
        int n = nums.size();
        vector<int> first_part, second_part;

        vector<int> a, b;
        for(int i =0; i < n/2; i++){
            a.push_back(nums[i]);
        }
        for(int i = n/2; i < n; i++){
            b.push_back(nums[i]);
        }

        rec(0, 0, a, first_part);
        rec(0, 0, b, second_part);

        sort(first_part.begin(), first_part.end());
        sort(second_part.begin(), second_part.end());

        // for(int i : first_part)
        //     cout<<i<<" ";
        // cout<<endl;
        // for(int i : second_part)
        //     cout<<i<<" ";

        for(int i = 0; i < first_part.size(); i++){
            int d = first_part[i];
            int e = goal - d;

            auto pos = lower_bound(second_part.begin(), second_part.end(), e);
            if(pos == second_part.begin()){
                ans = min(ans, abs(goal - (d + *pos)));
            }
            else if (pos == second_part.end()){
                pos = prev(pos);
                ans = min(ans, abs(goal - (d + *pos)));
            }
            else{
                ans = min(ans, abs(goal - (d + *pos)));
                pos = prev(pos);
                ans = min(ans, abs(goal - (d + *pos)));
            }
        }

        return ans;
    }
};