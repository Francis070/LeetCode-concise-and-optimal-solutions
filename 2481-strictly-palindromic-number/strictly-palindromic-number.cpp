class Solution {
public:
    bool chk_pal(string s){
        int n= s.size();
        for(int i = 0;i < n/2; i++){
            if(s[i] != s[n - i - 1])
                return false;
        }
        return true;
    }
    bool isStrictlyPalindromic(int n) {
        bool ans = true;
        int st = 2, end = n - 2;

        for(int i = st; i <= end; i++){
            string a = "";
            int t = n;

            while(t > 0){
                a = to_string(t%i) + a;
                t = t/i;
            }
            cout<<a<<endl;
            if(chk_pal(a) == false)
                return false;
        }

        return true;
    }
};