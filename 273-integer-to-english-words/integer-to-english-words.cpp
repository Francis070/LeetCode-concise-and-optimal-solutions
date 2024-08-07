class Solution {
public:

    string trimEndSpace(string s){
        int cnt = 0;
        int i = s.size() - 1;

        while(i >= 0 && s[i] == ' '){
            cnt++;
            i--;
        }

        return(s.substr(0, s.size() - cnt));
    }

    string getName(string s, bool & chk){
        
        int n = s.size();
        if(stoi(s) == 0){
            chk = false;
            return "";
        }
        stack<string > st;
        for(int i = 0; i < n; i++){
            if(i == 0){
                if(s[i] == '1')
                    st.push("One");
                else if(s[i] == '2')
                    st.push("Two");
                else if(s[i] == '3')
                    st.push("Three");
                else if(s[i] == '4')
                    st.push("Four");
                else if(s[i] == '5')
                    st.push("Five");
                else if(s[i] == '6')
                    st.push("Six");
                else if(s[i] == '7')
                    st.push("Seven");
                else if(s[i] == '8')
                    st.push("Eight");
                else if(s[i] == '9')
                    st.push("Nine");
            }
            else if(i == 1){
                if(s[i] == '1'){
                    if(s[0] == '0'){
                        st.push("Ten");
                    }
                    else{
                        st.pop();
                        if(s[0] == '1')
                            st.push("Eleven");
                        else if(s[0] == '2')
                            st.push("Twelve");
                        else if(s[0] == '3')
                            st.push("Thirteen");
                        else if(s[0] == '4')
                            st.push("Fourteen");
                        else if(s[0] == '5')
                            st.push("Fifteen");
                        else if(s[0] == '6')
                            st.push("Sixteen");
                        else if(s[0] == '7')
                            st.push("Seventeen");
                        else if(s[0] == '8')
                            st.push("Eighteen");
                        else if(s[0] == '9')
                            st.push("Nineteen");
                    }
                    
                }
                else{
                    if(s[i] == '2')
                        st.push("Twenty");
                    else if(s[i] == '3')
                        st.push("Thirty");
                    else if(s[i] == '4')
                        st.push("Forty");
                    else if(s[i] == '5')
                        st.push("Fifty");
                    else if(s[i] == '6')
                        st.push("Sixty");
                    else if(s[i] == '7')
                        st.push("Seventy");
                    else if(s[i] == '8')
                        st.push("Eighty");
                    else if(s[i] == '9')
                        st.push("Ninety");
                }
            }
            else {
                if(s[i] != '0')
                    st.push("Hundred");

                if(s[i] == '1')
                    st.push("One");
                else if(s[i] == '2')
                    st.push("Two");
                else if(s[i] == '3')
                    st.push("Three");
                else if(s[i] == '4')
                    st.push("Four");
                else if(s[i] == '5')
                    st.push("Five");
                else if(s[i] == '6')
                    st.push("Six");
                else if(s[i] == '7')
                    st.push("Seven");
                else if(s[i] == '8')
                    st.push("Eight");
                else if(s[i] == '9')
                    st.push("Nine");
            }
        }

        string ret = "";

        while(!st.empty()){
            if(st.top() != "")
                ret += (st.top() + " ");
            st.pop();
        }

        ret = ret.substr(0, ret.size() - 1);
        ret = trimEndSpace(ret);
        return ret;
    }

    string numberToWords(int num) {
        string s = to_string(num);
        if(s.size() == 1 && s[0] == '0')
            return "Zero";
        reverse(begin(s), end(s));
        stack<string> st;
        for(int i = 0; i < s.size(); i+=3){
            int gt = s.size() - i;
            string cur =  s.substr(i, min(3, gt));
            // reverse(begin(cur), end(cur));
            bool chk = true;
            string name = getName(cur, chk);

            if(i / 3 == 1 && chk){
                st.push("Thousand");
            }
            else if(i / 3 == 2 && chk){
                st.push("Million");
            }
            else if(i / 3 == 3 && chk){
                st.push("Billion");
            }
            else if(i / 3 == 4 && chk){
                st.push("Trillion");
            }

            st.push(name);
        }

        string ans = "";

        while(!st.empty()){
            if(st.top() != "")
                ans += st.top() + " ";
            st.pop();
        }

        ans = ans.substr(0, ans.size() - 1);
        ans = trimEndSpace(ans);
        return ans;
    }
};