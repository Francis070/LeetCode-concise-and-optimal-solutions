class Solution {
public:

    string unq(string s, vector<int> & v){
        string res = "";
        res += s[0];

        v.push_back(1);
        for(int i = 1; i < s.length(); i++){
            if(s[i] != res[res.size()-1]){
                res += s[i];
                v.push_back(1);
            }
            else{
                v.back()++;
            }
        }

        return res;
    }

    bool isLongPressedName(string name, string typed) {
        vector<int> v1, v2;
        string s1 = unq(name, v1), s2 = unq(typed, v2);
        // cout<<s1<<" "<<s2<<endl;

        if(s1 != s2)
            return false;

        for(int i =0 ; i < v1.size(); i++){
            if(v1[i] > v2[i])
                return false;
        }
        

        // for(int i =0; i < s1.size(); i++)
        //     if(m2[s1[i]] < m1[s1[i]])
        //         return false;
        
        return true;
    }
};