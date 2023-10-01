class Solution {
public:
    
    int fl(vector<int> &v, int target){
        int i = 0, j = 0;
        int ans = -1;
        long long cs = 0;
        while(j < v.size()){
            
            while(cs + v[j] > target){
                cs -= v[i++];
            }
            
            cs += v[j];

            if(cs == target){
                if(ans == -1)
                    ans = (j - i + 1);
                else
                    ans = min(ans, j - i + 1);
            }
            j++;
        }
        
        return ans;
    }
    
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        
        int ans = -1;
        
        vector<int> v(3 * n);
        long long bp = 0, cp = 0;
        for(int i = 0; i < 3*n; i++){
            v[i] = nums[i%n];
            bp += v[i];
        }
        // vector<int> er;
        // for(int i =0 ; i < 4*n; i++){
        //     er.push_back(nums[i%n]);
        // }
        
        cp = bp/3;
        // cout<<cp<<endl;
        
        
        if(target >= 2*cp){
            // cout<<"1--";
            long long cs = target%cp;
            
            if(cs == 0){
                ans = (target/cp) * n;
            }
            else{
                int res = fl(v, cs);
                if(res != -1){
                    ans = ((target/cp) * n) + res;
                }
            }
        }
        else{
            // cout<<"2--";
            ans = fl(v, target);
        }
        
        return ans;
        
    }
};