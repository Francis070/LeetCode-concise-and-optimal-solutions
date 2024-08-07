class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();

        stack<string> st;
        for(int i =0; i < n; i++){
            if(logs[i] == "../"){
                if(!st.empty())
                    st.pop();
            }
            else if(logs[i] == "./"){
                continue;
            }
            else{
                st.push(logs[i]);
            }
        }

        int ans = 0;

        while(!st.empty()){
            st.pop();
            ans++;
        }

        return ans;
    }
};