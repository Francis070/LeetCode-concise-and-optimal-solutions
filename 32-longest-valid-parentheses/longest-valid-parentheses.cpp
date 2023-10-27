class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        int ans = 0;
        for(int i =0; i < n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                if(!st.empty() && s[st.top()] == '(')
                    st.pop();
                else
                    st.push(i);
                
                if(!st.empty())
                    ans = max(ans, i - st.top());
                else
                    ans = max(ans, i + 1);
            }
        }

        return ans;
    }
};