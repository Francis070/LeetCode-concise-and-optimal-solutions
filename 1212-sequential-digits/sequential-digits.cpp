class Solution {
public:

    bool seq(int current){
        vector<int> v;
        
        int t = current;

        while(t > 0){
            int x = t%10;
            t = t/10;
            v.push_back(x);
        }

        reverse(v.begin(), v.end());
        int var = v[0] + 1;
        bool chk = false;
        for(int i = 1; i < v.size(); i++, var++){
            if(v[i] != var){
                return false;
            }
        }
        return true;
    }

    long get_next(int current){
        vector<int> v;
        
        int t = current;

        while(t > 0){
            int x = t%10;
            t = t/10;
            v.push_back(x);
        }

        reverse(v.begin(), v.end());
        // vector<int> exp(v.size());
        int var = v[0] + 1;
        int om = v[0] + 1;
        bool chk = false;
        for(int i = 1; i < v.size(); i++, var++){
            if(v[i] != var){
                if(v[i] < var){
                    for(int j = i; j < v.size(); j++, var++){
                        v[j] = var;
                    }
                }
                else{
                    for(int j = 0; j < v.size(); j++, om++){
                        v[j] = om;
                    }
                }
                chk  =true;
                break;
                
            }
        }

        // for(int x : v)
        //     cout<<x;

        if(!chk){
            int frs = v[0] + 1;

            for(int i = 0; i < v.size(); i++){
                if(v[i] + 1 >= 10){
                    v.push_back(0);
                    for(int i =0 ; i < v.size(); i++){
                        v[i] = i + 1;
                        if(v[i] >= 10)
                            return -1;
                    }
                    break;
                }
                else{
                    v[i]++;
                }
            }

            int x = 10;
            reverse(v.begin(), v.end());
            long ree = v[0];
            for(int i= 1; i < v.size(); i++){
                ree += (x * v[i]);
                x *= 10;
            }

            return ree;
        }
        else{
            for(int i = 0; i < v.size(); i++){
                if(v[i] >= 10){
                    v.push_back(0);
                    for(int i =0 ; i < v.size(); i++){
                        v[i] = i + 1;
                        if(v[i] >= 10)
                            return -1;
                    }
                    break;
                }
            }

            int x = 10;
            reverse(v.begin(), v.end());
            long ree = v[0];
            for(int i= 1; i < v.size(); i++){
                ree += (x * v[i]);
                x *= 10;
            }

            return ree;
        }

        return -1;
    }

    vector<int> sequentialDigits(int low, int high) {
        
        long ans = get_next(low);
        vector<int> res;
        if(seq(low)){
            res.push_back(low);
        }
        while(ans != -1 && ans <= high){
            res.push_back(ans);
            ans = get_next(ans);
        }

        return res;
    }
};