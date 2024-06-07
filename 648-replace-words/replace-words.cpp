class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        map<string, int> mp;
        for(string a : dictionary){
            mp[a]++;
        }
        string cur;
        string res;
        int n = sentence.size();
        for(int i =0;i < n; i++){
            if(sentence[i] != ' '){
                cur += sentence[i];
            }
            else{
                bool chk = false;
                for(int j = 0; j < cur.size(); j++){
                    if(mp.count(cur.substr(0, j + 1)) == 1){
                        chk = true;
                        res += cur.substr(0, j + 1);
                        break;
                    }
                }
                if(chk == false){
                    res += cur;
                }
                res += " ";
                cur = "";
            }
        }

        bool er = false;
        for(int j = 0; j < cur.size(); j++){
            if(mp.count(cur.substr(0, j + 1)) == 1){
                er = true;
                res += cur.substr(0, j + 1);
                break;
            }
        }
        if(er == false){
            res += cur;
        }

        // res = res.substr(0, res.size() - 1);

        return res;
    }
};