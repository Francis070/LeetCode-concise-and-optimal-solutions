class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<bool> ans;   
        for(int i = 0; i < m; i++){
            int st = l[i], en = r[i];

            vector<int> temp(en - st + 1);
            for(int j = st; j <= en; j++){
                // cout<<nums[j]<<" ";
                temp[j - st] = nums[j];
                // vt.push_back(nums[j]);
            }
            sort(temp.begin(), temp.end());
            // for(int k = 0;k < temp.size(); k++)
            //     cout<<temp[k]<<" ";
            // cout<<endl;

            if(temp.size() == 1)
                ans.push_back(true);
            else{
                int dif = temp[1] - temp[0];
                bool flg = false;
                for(int h = 1; h < temp.size(); h++)
                    if((temp[h] - temp[h-1]) != dif){
                        ans.push_back(false);
                        flg = true;
                        break;
                    }
                if(flg == false)
                    ans.push_back(true);
            }
                
        }

        return ans;
    }
};