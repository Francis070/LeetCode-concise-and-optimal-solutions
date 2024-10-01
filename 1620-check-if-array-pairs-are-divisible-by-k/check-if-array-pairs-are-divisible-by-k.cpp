class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();

        unordered_map<int, int> um;
        for(int i : arr){
            um[(i%k + k)%k]++;
        }

        // for(auto x : um){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }

        for(auto x : um){
            int fr = x.first;
            int se = k - fr;
            int re = -fr;

            if(fr == 0){
                if(x.second % 2 != 0)
                    return false;
            }
            else {
                if(!((fr == se && x.second%2 == 0) || (um[fr] == um[se]) || (um[fr] == um[re] )))               return false;
            }
        }
        return true;
    }
};