class Solution {
public:

    int gt(string & s, string sub){
        stack<char> st;
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == sub[1] && !st.empty() && st.top() == sub[0]){
                cnt++;
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        string t = "";
        while(!st.empty()){
            t += st.top();
            st.pop();
        }

        reverse(begin(t), end(t));
        s = t;

        return cnt;
    }

    int maximumGain(string s, int x, int y) {
        int ans = 0;

        if(x > y){
            ans += (gt(s, "ab") * x);

            ans += (gt(s, "ba") * y);
        }
        else{
            ans += (gt(s, "ba") * y);
            ans += (gt(s, "ab") * x);

        }

        return ans;
    }
};