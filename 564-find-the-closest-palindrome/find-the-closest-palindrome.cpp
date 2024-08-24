class Solution {
public:

    string nextGreaterPal(string n){
        long long cur = stoll(n);
        cur += 1;
        string t = to_string(cur);
        int l = t.size();
        vector<int> v(t.size());

        for(int  i = 0; i < l; i++){
            v[i] = t[i] - '0';
        }

        int left = (l % 2) == 0 ? ((l/2) - 1): (l/2);
        int right = (l % 2) == 0 ? (l/2): (l/2);
        int d = 0;
        while(left >= 0){
            if(v[left] != v[right]){
                if(v[left] < v[right]){
                    if(d == 0){
                        d++;
                        v[left]++;
                        int se = (l % 2) == 0 ? ((l/2) - 1): (l/2);
                        int ps = -1;
                        for(int i = se; i > left; i--){
                            if(v[i] < 9){
                                ps = i;
                                break;
                            }
                        }

                        if(ps == -1){
                            v[right] = v[left];

                            for(int i = left + 1; i < right; i++)
                                v[i] = 0;
                        }
                        else{
                            v[left]--;
                            v[right] = v[left];
                            v[ps]++;
                            v[l - ps - 1] = v[ps];
                            for(int i = ps + 1; i < (l - ps - 1); i++)
                                v[i] = 0;
                        }
                        
                    }
                    else{
                        v[right] = v[left];
                    }
                }
                else{
                    v[right] = v[left];
                    d++;
                }
            }

            left--;
            right++;
        }

        string res = "";

        for(int i = 0; i < v.size(); i++){
            res += ('0' + v[i]);
        }

        return res;
    }

    string nextSmallerPal(string n){
        long long cur = stoll(n);
        cur -= 1;
        string t = to_string(cur);
        int l = t.size();
        vector<int> v(t.size());
        // cout<<t<<endl;
        for(int  i = 0; i < l; i++){
            v[i] = t[i] - '0';
        }

        int left = (l % 2) == 0 ? ((l/2) - 1): (l/2);
        int right = (l % 2) == 0 ? (l/2): (l/2);
        int d = 0; //used to check if something is reduced or not
        while(left >= 0){
            if(v[left] != v[right]){
                if(v[left] < v[right]){
                    // v[left]++;
                    // v[right] = v[left];

                    // for(int i = left + 1; i < right; i++)
                    //     v[i] = 0;
                    v[right] = v[left];
                    d++;
                }
                else{
                    if(d == 0){
                        d++;
                        v[left]--;
                        if(left == 0 && v[left] == 0){
                            int se = (l % 2) == 0 ? ((l/2) - 1): (l/2);
                            int ps = -1;
                            for(int i = se; i > left; i--){
                                if(v[i] > 0){
                                    ps = i;
                                    break;
                                }
                            }

                            if(ps == -1){
                                for(int i = left + 1 ; i< l; i++)
                                v[i] = 9;
                            }
                            else{
                                v[left] = 1;
                                v[right] = 1;
                                v[ps]--;
                                v[l - ps - 1] = v[ps];
                                for(int i = ps + 1; i < (l - ps - 1); i++)
                                    v[i] = 9;
                            }
                            
                        }
                        else{
                            //check if before reducing left is there any element that can be reduced
                            int se = (l % 2) == 0 ? ((l/2) - 1): (l/2);
                            int ps = -1;
                            for(int i = se; i > left; i--){
                                if(v[i] > 0){
                                    ps = i;
                                    break;
                                }
                            }

                            if(ps == -1){
                                v[right] = v[left];
                                for(int i = left + 1; i < right; i++)
                                    v[i] = 9;
                            }
                            else{
                                v[left]++;
                                v[right] = v[left];
                                v[ps]--;
                                v[l - ps - 1] = v[ps];
                                for(int i = ps + 1; i < (l - ps - 1); i++)
                                    v[i] = 9;
                            }
                            
                        }
                    }
                    else{
                        v[right] = v[left];
                    }
                }
            }

            left--;
            right++;
        }

        string res = "";

        for(int i = 0; i < v.size(); i++){
            res += ('0' + v[i]);
        }
        // cout<<res<<endl;
        return res;
    }

    string nearestPalindromic(string n) {

        string ngp = nextGreaterPal(n);
        string nsp = nextSmallerPal(n);

        // cout<<ngp<<" "<<nsp<<endl;
        long long sp = stoll(nsp);
        long long gp = stoll(ngp);

        long long cur = stoll(n);
        // cout<<sp<<" "<<gp<<endl;
        if(abs(cur - sp) == abs(cur - gp)){
            return to_string(sp);
        }
        else{
            long long res = abs(cur - sp) < abs(cur - gp) ?  sp: gp;
            return to_string(res);
        }
    }
};