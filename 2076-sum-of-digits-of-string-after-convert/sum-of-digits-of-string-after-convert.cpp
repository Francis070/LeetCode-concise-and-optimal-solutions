class Solution {
public:
    int getLucky(string s, int k) {
        
        int n = s.size();

        string num = "";

        for(char c : s){
            int cr = (c - 'a' + 1);
            num += to_string(cr);
        }
        string f = "";
        while(k--){
            int fn = 0;
            for(char c : num)
                fn += (c - '0');

            num = to_string(fn);
        }

        return stoi(num);
    }
};