class Solution {
public:

    vector<string> getS(string ss){
        vector<string> s;
        string r = "";
        for(char c : ss){
            if(c == ' '){
                s.push_back(r);
                r = "";
            }
            else 
                r += c;
        }
        s.push_back(r);
        return s;
    }

    bool areSentencesSimilar(string s1, string s2) {
        vector<string> v1, v2;

        v1 = getS(s1);
        v2 = getS(s2);

        if(v1.size() > v2.size())
            return areSentencesSimilar(s2, s1);

        int  s= 0, e = v1.size() - 1, ss = 0, ee = v2.size() - 1;

        while(s <= e){
            if(v1[s] == v2[ss] || v1[e] == v2[ee]){
                if(v1[s] == v2[ss]){
                    ss++;
                    s++;
                }
                else{
                    e--;
                    ee--;
                }
            }
            else {
                return false;
            }
        }

        return true;
    }
};