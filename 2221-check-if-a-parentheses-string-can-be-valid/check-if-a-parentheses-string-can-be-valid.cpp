class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        stack<pair<char, int>> st_l, st_notl;

        for(int i = 0; i < n; i++){
            if(s[i] == ')'){
                if(locked[i] == '1'){
                    if(st_l.empty() && st_notl.empty()){
                        return false;
                    }
                    else{
                        if(!st_l.empty())
                            st_l.pop();
                        else
                            st_notl.pop();
                    }
                }
                else{
                    st_notl.push({s[i], i});
                }
            }
            else{
                if(locked[i] == '1'){
                    st_l.push({s[i], i});
                }
                else{
                    st_notl.push({s[i], i});
                }
            }
        }

        while(!st_l.empty()){
            if(st_notl.empty() || st_notl.top().second < st_l.top().second){
                return false;
            }
            st_l.pop();
            st_notl.pop();
        }

        if(!st_notl.empty() && st_notl.size() % 2 == 1){
            return false;
        }
        return true;
    }
};