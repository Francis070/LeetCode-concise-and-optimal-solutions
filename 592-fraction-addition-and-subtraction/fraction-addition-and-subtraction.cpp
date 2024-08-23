class Solution {
public:
    string fractionAddition(string expression) {
        int n = expression.size();        
        vector<int> deno, num;

        for(int i = 0; i < n; i++){
            if(expression[i] == '/'){
                int j = i + 1;
                string den = "";
                while(j < n && expression[j] <= '9' && expression[j] >= '0'){
                    den += expression[j];
                    j++;
                }

                j = i - 1;
                string nume = "";
                while(j >= 0 && (expression[j] <= '9' && expression[j] >= '0')){
                    nume = expression[j] + nume;
                    j--;
                }

                if(j >= 0){
                    nume = expression[j] + nume;
                }

                deno.push_back(stoi(den));
                num.push_back(stoi(nume));
                // cout<<den<<" "<<nume<<endl;
            }
        }
        int gcd = 1;
        int mult = 1;
        for(int i = 0; i < deno.size(); i++){
            // int cn = stoi(deno[i]);
            gcd = __gcd(gcd, deno[i]);
            mult *= deno[i];
        }

        int lcm = mult/gcd;
        int ts = 0;
        for(int i = 0; i < deno.size(); i++){
            ts += (lcm/deno[i]) * num[i];
        }

        while(__gcd(abs(ts), lcm) != 1){
            int cg = __gcd(abs(ts), lcm);
            ts /= cg;
            lcm/= cg;
        }
        string res = to_string(ts) + "/" + to_string(lcm);
        // cout<<ts<<"/"<<lcm<<endl;
        return res;
    }
};