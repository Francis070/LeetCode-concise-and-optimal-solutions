class Solution {
public:

    double get_ans(string num, string den, bool &chk, vector<vector<string>>& equations, vector<double>& values, vector<int> & vis){
        // vis[pos] = 1;   
        int n = values.size();
        // int ans = 1.0;

        for(int i = 0; i < n; i++){
            if(vis[i] == 0 && (equations[i][0] == num || equations[i][1] == num)){
                
                vis[i] = 1;
                // cout<<i<<endl;
                // for(int t = 0; t < n; t++)
                //     cout<<vis[t]<<" ";
                // cout<<endl;
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
                            // return values[i] * get_ans(equations[i][1], den, chk, equations, values, vis);
                            // if(chk)
                            // return ans;
                        }
                        else{
                            double ser =  get_ans(equations[i][0], den, chk, equations, values, vis);
                            if(chk)
                                return (1.0/values[i]) * ser;
                        }

                        
                    }
                }
                // vis[i] = 0;
            }
        }

        return 1.0;
    }

    vector<int> get_sources(vector<vector<string>>& equations, string num){
        int n = equations.size();
        vector<int> src;
        for(int i = 0; i < n; i++){
            if(equations[i][0] == num || equations[i][1] == num)
                src.push_back(i);
        }

        return src;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size(), m = queries.size();

        vector<double> ans(m, -1.0);

        for(int i =0; i < m; i++){
            string num = queries[i][0];
            string den = queries[i][1];

            // vector<int> srcs = get_sources(equations, num);

            // for(int j = 0; j < srcs.size(); j++){
            //     

            //     double cur = get_ans(num, den, srcs[j], equations, values, vis);
            //     if(cur != -1.0)
            //         ans[i] = cur;
            // }
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