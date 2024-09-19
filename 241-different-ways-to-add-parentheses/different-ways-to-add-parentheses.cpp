class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        int n = exp.size();
        vector<int> res;

        for(int i = 0; i < n; i++){
            if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*'){
                vector<int> res1 = diffWaysToCompute(exp.substr(0, i));
                vector<int> res2 = diffWaysToCompute(exp.substr(i + 1, n - i - 1));

                for(int x = 0; x < res1.size(); x++){
                    for(int y = 0; y < res2.size(); y++){
                        int cur;
                        if(exp[i] == '+'){
                            cur = res1[x] + res2[y];
                        }
                        else if(exp[i] == '-'){
                            cur = res1[x] - res2[y];
                        }   
                        else
                            cur = res1[x] * res2[y];
                        res.push_back(cur);
                    }
                }
            }
        }
        if(res.size() == 0)
            res.push_back(stoi(exp));

        return res;
    }
};