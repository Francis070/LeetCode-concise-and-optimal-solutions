class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();

        stack<int> op, st;

        for(int i =0; i < n; i++){
            if(s[i] == ')'){
                if(op.empty()){
                    if(st.empty()){
                        return false;
                    }
                    else{
                        st.pop();
                    }
                }
                else{
                    op.pop();
                }
            }
            else if(s[i] == '*'){
                st.push(i);
            }
            else{
                op.push(i);
            }
        }

        if(!op.empty()){
            while(!op.empty()){
                if(st.empty())
                    return false;
                else{
                    if(st.top() < op.top())
                        return false;
                    else{
                        st.pop();
                        op.pop();
                    }
                }
            }
        }

        if(op.empty())
            return true;
        return false;
    }
};