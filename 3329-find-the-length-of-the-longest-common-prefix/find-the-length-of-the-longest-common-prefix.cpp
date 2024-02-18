class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> f, s;
        
        for(int w : arr1){
            string t = to_string(w);
            string d = "";
            for(char c : t){
                d += c;
                f.insert(d);
            }
        }

        for(int w : arr2){
            string t = to_string(w);
            string d = "";
            for(char c : t){
                d += c;
                s.insert(d);
            }
        }
        int ans =0 ;
        for(auto x : s){
            if(f.find(x) != f.end())
                ans = max(ans, int(x.size()));
        }


        return ans;
    }
};