class Solution {
public:

    double get_ans(string num, string den, bool &chk, vector<vector<string>>& equations, vector<double>& values, vector<int> & vis){
        int n = values.size();

        for(int i = 0; i < n; i++){
            if(vis[i] == 0 && (equations[i][0] == num || equations[i][1] == num)){
                
                vis[i] = 1;
                if(equations[i][0] == den || equations[i][1] == den){
                    chk = true;
                    if(num == den)
                        return 1.0;
                    if(equations[i][0] == den){
                        return (1.0 / values[i]);
                    }
                    else    
                        return values[i];
                }
                else{
                    if(chk == false){

                        if(equations[i][0] == num){
                            double ser = get_ans(equations[i][1], den, chk, equations, values, vis);
                            if(chk)
                                return values[i] * ser;
                        }
                        else{
                            double ser =  get_ans(equations[i][0], den, chk, equations, values, vis);
                            if(chk)
                                return (1.0/values[i]) * ser;
                        }

                        
                    }
                }
            }
        }

        return 1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size(), m = queries.size();

        vector<double> ans(m, -1.0);

        for(int i =0; i < m; i++){
            string num = queries[i][0];
            string den = queries[i][1];

            vector<int> vis(n, 0);
            bool chk = false;
            double cur = get_ans(num, den, chk, equations, values, vis);
            if(chk == false)
                ans[i] = -1;
            else
                ans[i] = cur;
        }

        return ans;
    }
};