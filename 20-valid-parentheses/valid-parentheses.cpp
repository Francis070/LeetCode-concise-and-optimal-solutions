class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                if(st.empty())
                    return false;
                else{
                    char top = st.top();
                    if(top == '(' && s[i] == ')')
                        st.pop();
                    else if(top == '[' && s[i] == ']')
                        st.pop();
                    else if(top == '{' && s[i] == '}')
                        st.pop();
                    else
                        return false;
                }
            }
            else
                st.push(s[i]);
        }

        if(st.size() > 0)
            return false;
        
        return true;
    }
};