class Solution {
public:

    float calc(vector<float> &cur){
        float res = cur[0];
        for(int i = 1; i < cur.size(); i++){
            res /= cur[i];
        }

        return res;
    }

    void eval(vector<int> &nums, vector<int> &er, unordered_map<float, vector<int>> &um){
        int n = er.size();
        // for(int i = 0; i< n; i++){
        //     cout<<er[i]<<" ";
        // }
        // cout<<endl;
        vector<int> vc = er;
        int t = 0;
        for(int i = 0; i < n; i++)
            if(vc[i] != 0)
                t++;
        for(int i = 1; i < n; i++)
            if(vc[i-1] == 1 && vc[i] == 0)
                vc[i] = 1;
        // for(int i = 0; i< n; i++){
        //     cout<<vc[i]<<" ";
        // }
        // cout<<endl;
            
        vector<float> uni, cur;

        for(int i = 0; i < n-1; i++){
            if((vc[i] == 1) && (vc[i + 1] == 1)){
                int j = i;
                while((j < n-1) && ((vc[j] == 1)&& (vc[j + 1] == 1))){
                    cur.push_back(nums[j]);
                    j++;
                }
                cur.push_back(nums[j]);
                i = j;
            }
            float temp;
            if(cur.size() > 0){
                // for(int i = 0; i< cur.size(); i++){
                //     cout<<cur[i]<<" ";
                // }
                // cout<<endl;
                temp = calc(cur);
                cur.clear();
            }
            else
                temp = nums[i];

            uni.push_back(temp);
        }
        // for(int i = 0; i< uni.size(); i++){
        //     cout<<uni[i]<<" ";
        // }
        // cout<<"---"<<endl;
        float df = calc(uni);
        // cout<<df<<endl;
        if(um.find(df) != um.end()){
            int y = 0;
            for(int i = 0; i < n; i++){
                if(um[df][i] != 0)
                    y++;
            }

            if(t < y)
                um[df] = er;
        }
        else
            um[df] = er;
    }

    void rec(int ind, int n, bool chk, vector<int> &nums, vector<int> vc, unordered_map<float, vector<int>> &um){
        if(ind >= n){
            if(chk == false){
                eval(nums, vc, um);
            }

            return;
        }

        if(chk){
            vc[ind] = -1;
            rec(ind + 1, n, false, nums, vc, um);
            vc[ind] = 0;
            rec(ind + 1, n, true, nums, vc, um);
        }
        else{
            vc[ind] = 1;
            rec(ind + 1, n, true, nums, vc, um);
            vc[ind] = 0;
            rec(ind + 1, n, false, nums, vc, um);
        }

    }

    string convert(vector<int>& res, vector<int>& nums){
        string r = "";
        int n = nums.size();
        for(int i = 0; i< n; i++){
            if(res[i] == 1){
                r += '(';

            }
            r += to_string(nums[i]);
            if(res[i + 1] == -1){
                r += ')';
            }
            r += '/';
        }

        if(r[r.size() -1] == '/'){
            r = r.substr(0, r.size() - 1);
        }

        return r;
    }

    string optimalDivision(vector<int>& nums) {
        unordered_map<float, vector<int>> um;
        int n = nums.size();

        vector<int> vc(n + 1, 0);
        bool chk = false;
        rec(0, n + 1, chk, nums, vc, um);

        float val = -1;
        vector<int> res;
        for(auto & x : um){
            if(x.first > val){
                val = x.first;
                res = x.second;
            }
        }

        // for(auto & x : um){
        //     cout<<x.first<<endl;
        // }

        string ans = "";
        ans = convert(res, nums);

        return ans;
    }
};