class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n = s.size();

        int m = chars.size();
        unordered_map<char, int> um;
        for(int i = 0; i < m; i++){
            um[chars[i]] = vals[i];
        }

        vector<int> v(n);

        for(int i = 0; i < n; i++){
            if(um.count(s[i])){
                v[i] = um[s[i]];
            }
            else{
                v[i] = (s[i] - 'a' + 1);
            }
        }


        //kadane

        int ans = 0;
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += v[i];
            if(sum < v[i]){
                sum = v[i];
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};