class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int e = pow(2, n);

        vector<int> check(e, 0), perm(e, 0);
        check[0] = 1;
        int i = 1, j = e-1;
        int vi = 0, vj = 0;

        while(i < j){
            
            //vi
            for(int a = 0; a < n; a++){
                int r = 1<<a;
                if((r & vi) > 0){
                    if(check[vi-r] == 0){
                        check[vi-r] = 1;
                        vi = vi-r;
                        perm[i] = vi;
                        break;
                    }
                }
                else{
                    if(check[vi + r] == 0){
                        check[vi + r] = 1;
                        vi = vi + r;
                        perm[i] = vi;
                        break;
                    }
                }
            }

            for(int a = 0; a < n; a++){
                int r = 1<<a;
                if((r & vj) > 0){
                    if(check[vj-r] == 0){
                        check[vj-r] = 1;
                        vj = vj-r;
                        perm[j] = vj;
                        break;
                    }
                }
                else{
                    if(check[vj + r] == 0){
                        check[vj + r] = 1;
                        vj = vj + r;
                        perm[j] = vj;
                        break;
                    }
                }
            }
            // cout<<i<<" "<<vi<<" "<<j<<" "<<vj<<endl;
            i++; j--;
        }
        for(int k = 0; k < e; k++){
            if(check[k] == 0){
                perm[i] = k;
                break;
            }
        }
        int pos = -1;
        for(int k = 0; k < e; k++){
            if(perm[k] == start){
                pos = k;
                break;
            }
        }
        
        vector<int> ans;

        for(int k = pos; k < e; k++){
            ans.push_back(perm[k]);
        }
        for(int k = 0; k < pos; k++){
            ans.push_back(perm[k]);
        }
        return ans;
    }
};