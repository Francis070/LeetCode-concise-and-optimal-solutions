class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();

        int pop_limit = k;
        stack<char> st;
        for(int i = 0; i < n; i++){
            while(pop_limit > 0 && !st.empty() && (num[i] < st.top())){
                // if(num[i] == st.top() && num[i] == '0')
                //     break;
                st.pop();
                pop_limit--;
            }

            st.push(num[i]);
        }

        while(!st.empty() && pop_limit > 0){
            st.pop();
            pop_limit--;
        }
        

        string ans = "";
        vector<char> vc;
        while(!st.empty()){
            char x = st.top();
            vc.push_back(x);
            st.pop();
            // ans = x + ans;
            // st.pop();
        }

        reverse(vc.begin(), vc.end());
        for(int i = 0; i < vc.size(); i++)
            ans += vc[i];

        // cout<<n<<" "<<ans.size()<<endl;

        int zero = 0;
        while(ans[zero] == '0' && zero < ans.size())
            zero++;
        
        ans = ans.substr(zero, ans.size() - zero);
        if(ans.size() == 0)
            return "0";
        return ans;
    }
};