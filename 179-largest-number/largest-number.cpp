class Solution {
public:

    static bool comp(string a, string b){
        string er = a + b;
        string fr = b + a;
        return (er >= fr);
    }

    string removeStartZero(string a){
        bool chk = false;
        string er = "";
        for(int i = 0; i < a.size(); i++){
            if(a[i] != '0'){
                chk = true;
            }
            if(chk){
                er += a[i];
            }
        }

        if(!chk)
            return "0";
        
        return er;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> vs;
        int zc = 0;
        for(auto x : nums){
            vs.push_back(to_string(x));
            if(x == 0)
                zc++;
        }

        if(zc == nums.size())
            return "0";

        sort(begin(vs), end(vs), comp);
        
        string res = "";
        for(string s : vs)
            res += s;

        string ans = removeStartZero(res);
        cout<<res;
        
        return res;
    }
};