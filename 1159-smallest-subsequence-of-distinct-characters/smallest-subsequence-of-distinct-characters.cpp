class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();

        stack<int> st;
        
        unordered_map<char, int> overall, current;

        for(char c : s)
            overall[c]++;

        for(int i = 0; i < n; i++){
            while(!st.empty() && s[i] < s[st.top()] && overall[s[st.top()]] > 1 && current[s[i]] == 0){
                overall[s[st.top()]]--;
                current[s[st.top()]] = max(0, current[s[st.top()]] - 1);
                st.pop();
            }

            if(current[s[i]] == 0){
                current[s[i]]++;
                st.push(i);
            }
            else{
                overall[s[i]]--;
            }
        }

        string ans = "";

        while(!st.empty()){
            ans = s[st.top()] + ans;
            st.pop();
        }

        return ans;
    }
};