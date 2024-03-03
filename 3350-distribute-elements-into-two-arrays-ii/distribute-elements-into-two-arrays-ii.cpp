#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds; 

typedef tree<pair<int,int>, null_type,  
        less<pair<int,int>>, rb_tree_tag, 
        tree_order_statistics_node_update> 
        ordered_set; 

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> a, b;
        unordered_map<int, int> ca, cb;
        ordered_set sa, sb;
        
        a.push_back(nums[0]);
        b.push_back(nums[1]);
        ca[nums[0]]++;
        cb[nums[1]]++;
        
        sa.insert({nums[0], 0});
        sb.insert({nums[1], 1});
        
        for(int i = 2; i < n; i++){
            int os1 = sa.size(), os2 = sb.size();
            
            //greater a
            int ga = os1 - (sa.order_of_key({nums[i], -1}) + ca[nums[i]]);
            
            //greater b
            int gb = os2 - (sb.order_of_key({nums[i], -1}) + cb[nums[i]]);
            
            if(ga != gb){
                if(ga > gb){
                    a.push_back(nums[i]);
                    ca[nums[i]]++;
                    sa.insert({nums[i], i});
                }
                else{
                    b.push_back(nums[i]);
                    cb[nums[i]]++;
                    sb.insert({nums[i], i});
                }
            }
            else{
                if(a.size() != b.size()){
                    if(a.size() < b.size()){
                        a.push_back(nums[i]);
                        ca[nums[i]]++;
                        sa.insert({nums[i], i});
                    }
                    else{
                        b.push_back(nums[i]);
                        cb[nums[i]]++;
                        sb.insert({nums[i], i});
                    }
                }
                else{
                    a.push_back(nums[i]);
                    ca[nums[i]]++;
                    sa.insert({nums[i], i});
                }
            }
        }

        for(int i =0 ; i < b.size(); i++){
            a.push_back(b[i]);
        }
        
        return a;
    }
};