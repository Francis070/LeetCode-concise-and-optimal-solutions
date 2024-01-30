class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();

        stack<string> str;
        for(int i =0 ;i < n; i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
                str.push(tokens[i]);
            else{
                int a = stoi(str.top()); str.pop();
                int b = stoi(str.top()); str.pop();
                int temp = 0;
                if(tokens[i] == "+")
                    temp = a+ b;
                else if(tokens[i] == "-")
                    temp = b - a;
                else if(tokens[i] == "*")
                    temp = a * b;
                else if(tokens[i] == "/")
                    temp = b / a;
                cout<<i <<" "<<temp<<endl;
                str.push(to_string(temp));
            }
        }

        int ans = stoi(str.top());
        return ans;
    }
};