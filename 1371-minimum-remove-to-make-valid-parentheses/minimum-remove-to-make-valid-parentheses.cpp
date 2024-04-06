class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int used = 0, cls= 0, opn = 0;
        int n = s.size();
        // for ( -> if there is no cls left and all are used then remove (. 
        // else use one ) and used++ and cls--;

        // for ) -> if used > 0 then used-- 
        // if used == 0 then cls-- and remove ) 
        for(char c: s)
            if(c == ')')
                cls++;
        vector<int> v(n, 0);     
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                if(cls == 0)
                    v[i] = 1;
                else{
                    cls--;
                    used++;
                }
            }
            else if(s[i] == ')'){
                if(used > 0){
                    used--;
                }
                else{
                    cls--;
                    v[i] = 1;
                }
            }
        }

        string res = "";
        for(int i =0 ; i < n; i++){
            if(v[i] == 0)
                res += s[i];
        }

        return res;
    }
};