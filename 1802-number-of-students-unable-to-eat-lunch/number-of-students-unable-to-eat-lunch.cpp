class Solution {
public:
    int countStudents(vector<int>& st, vector<int>& sa) {
        int n = st.size();

        int sto = 0, stz = 0, sao = 0, saz = 0;

        for(int i =0 ; i< n; i ++){
            if(st[i] == 0) stz++;
            else    sto++;
            if(sa[i] == 0)saz++;
            else sao++;
        }

        if(sto < sao || stz < saz){
            if(sto < sao){
                int cnt = 0;
                int pos = 0;
                for(int j = 0; j < n; j++){
                    if(sa[j] == 1) cnt++;
                    if(cnt > sto){
                        pos = j;
                        break;
                    }
                }
                return (n- pos);
            }
            else{
                int cnt = 0;
                int pos = 0;
                for(int j = 0; j < n; j++){
                    if(sa[j] == 0) cnt++;
                    if(cnt > stz){
                        pos = j;
                        break;
                    }
                }
                return (n- pos);
            }
        }
        
        return 0;
    }
};