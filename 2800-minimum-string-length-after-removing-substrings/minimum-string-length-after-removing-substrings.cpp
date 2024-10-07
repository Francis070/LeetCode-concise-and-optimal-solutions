class Solution {
public:
    int minLength(string s) {
        stack<char> st;

        for(char c  : s){
            if(!st.empty()){
                if(c - st.top() == 1 && (c == 'B' || c == 'D')){
                    st.pop();
                }
                else{
                    st.push(c);
                }
            }
            else{
                st.push(c);
            }
        }

        return st.size();
    }
};