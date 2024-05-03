class Solution {
public:

    vector<string> getDivider(string s){
        int n = s.size();

        string s1 = "";
        vector<string> res;
        for(int i =0; i < n; i++){
            if(s[i] == '.'){
                res.push_back(s1);
                s1 = "";
            }
            else{
                s1 += s[i];
            }
        }

        res.push_back(s1);

        return res;
    }

    vector<string> cleanAndConcat(vector<string> v){
        int n = v.size();
        // string res = "";
        vector<string> res;
        for(int i =0; i < n; i++){
            string cur = v[i];

            string bn = "";
            bool gt = false;
            for(int j = 0; j< cur.size(); j++){
                if(cur[j] == '0'){
                    if(gt)
                        bn += '0';
                }
                else{
                    gt = true;
                    bn += cur[j];
                }
            }

            if(bn.size() == 0)
                bn += '0';

            // v[i] = bn;
            // res += bn;
            if(bn.size() > 0)
                res.push_back(bn);
        }

        return res;
    }

    int compare(vector<string> s1, vector<string> s2){
        int n = min(s1.size(), s2.size());

        for(int i =0; i< n; i++){
            int y = stoi(s1[i]);
            int z = stoi(s2[i]);

            // cout<<y<<" "<<z<<endl;

            if(y < z)
                return -1;
            else if(y > z)
                return 1;
            // else if(y == z)
            //     return 0;
        }

        if(s1.size() < s2.size()){
            for(int i = n; i < s2.size(); i++){
                if(stoi(s2[i]) != 0)
                    return -1;
            }
            return 0;
        }
        else if(s2.size() < s1.size()){
            for(int i = n; i < s1.size(); i++){
                if(stoi(s1[i]) != 0)
                    return 1;
            }
            return 0;
        }
        
        return 0;
    }

    int compareVersion(string version1, string version2) {
        vector<string> v1, v2, v3, v4;

        v1 = getDivider(version1);
        v2 = getDivider(version2);

        v3 = cleanAndConcat(v1);
        v4 = cleanAndConcat(v2);
        // cout<<v3.size()<<" "<<v4.size()<<endl;
        // for(auto x : v3){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x : v4){
        //     cout<<x<<" ";
        // }
        // cout<<endl;

        int ans = compare(v3, v4);

        return ans;
    }
};