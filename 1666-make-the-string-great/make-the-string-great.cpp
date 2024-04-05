class Solution {
public:
    string makeGood(string s) {
        stack<char> st;

        for(char c : s){
            if(!st.empty() && (char)tolower(c) == (char)tolower(st.top()) && c != st.top()){
                st.pop();
            }
            else{
                st.push(c);
            }
        }

        string ans = "";
        while(!st.empty()){
            char c = st.top();
            st.pop();
            ans = c + ans;
        }

        return ans;
    }
};