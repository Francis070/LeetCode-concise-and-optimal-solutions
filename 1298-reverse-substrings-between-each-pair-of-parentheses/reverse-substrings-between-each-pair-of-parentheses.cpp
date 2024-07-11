class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int n = s.size();
        for(int i =0; i < n; i++){
            if(s[i] == ')'){
                string temp = "";

                while(!st.empty() && st.top() != '('){
                    temp += st.top();
                    st.pop();
                }

                st.pop();
                for(char c : temp){
                    st.push(c);
                }

            }
            else{
                st.push(s[i]);
            }
        }

        string ans = "";

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(begin(ans), end(ans));
        return ans;
    }
};