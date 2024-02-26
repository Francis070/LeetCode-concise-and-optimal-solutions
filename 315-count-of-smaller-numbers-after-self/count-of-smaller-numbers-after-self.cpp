#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

class Solution {
public:

    static bool comp(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> vp(n);
        for(int i = 0; i < n; i++){
            vp[i].first = nums[i];
            vp[i].second = i;
        }

        sort(begin(vp), end(vp));

        ordered_set p;
        for(int i = 0; i < n; i++){
            p.insert(vp[i].second);
            int sz = p.size();
            int pos = p.order_of_key(vp[i].second);

            vp[i].first = sz - pos - 1;
        }

        sort(begin(vp), end(vp), comp);
        vector<int> ans(n);
        for(int i =0; i < n; i++){
            ans[i] = vp[i].first;
        }

        return ans;
    }
};